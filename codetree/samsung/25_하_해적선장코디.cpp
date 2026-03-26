/**
 * 풀이 시간: 1H 20M
 * 풀이 아이디어: 2가지 상태에 따른 각각의 priority queue를 정의한다. pq에 이미 들어간
 * 데이터에 대해 수정사항이 있는 경우 lazy update를 사용한다.
 * 실수: 선박의 아이디가 10의 9승까지이므로 배열로 선언하면 안되고 map을 활용한다.
 */

#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

struct Info {
    int power, num;
    bool operator < (const Info& a) const {
        if (power != a.power) return power < a.power; // 1순위: power 큼
        else return num > a.num; // 2순위: 선박번호 작음
    }
};

using p = pair<int,Info>;
using mp= map<int,int>;

struct cmp {
    bool operator() (p &a, p&b){
        if (a.first!=b.first) return a.first > b.first; // 1순위: 재장전 시간 짧
        else if (a.second.power!=b.second.power){
            return a.second.power < b.second.power; // 2순위: power 큼
        } else return a.second.num > b.second.num; // 3순위: 선박번호 작음
    }
};

int T, N, currTime=0;
priority_queue<Info> readyQ; // 장전 완료 큐
priority_queue<p, vector<p>, cmp> reloadQ; // 장전 중인 큐

mp reloadTime;
mp powerArr;
mp readyTime;

void attack(){
    int powerSum=0; int shipCnt=0; string shipStr= "";
    while (!readyQ.empty() && shipCnt<5){
        // 꺼냈을 때 최신 공격력과 다르다면 유령 데이터
        auto [p, id]= readyQ.top(); readyQ.pop();

        if (p != powerArr[id]) continue;

        // 정답에 반영
        powerSum+=p; shipCnt++; shipStr= shipStr + to_string(id) + " ";

        // reloadQ에 넣음
        reloadQ.push({currTime+ reloadTime[id], {p, id}});  
        // cout << "재장전 후 시간 " << currTime+ reloadTime[id] << "\n";
        readyTime[id]= currTime+reloadTime[id];    
    }
    cout << powerSum << " " << shipCnt << " " << shipStr << "\n";
}

void replaceShip(){
    int id, pw;
    cin >> id >> pw;
    powerArr[id]= pw;

    // 여기서 두 가지 큐 중 어디에 넣어야 하는지?
    if (readyTime[id] <= currTime){
        readyQ.push({pw, id});
    } else {
        reloadQ.push({readyTime[id], {pw, id}});
    }
}

void addShip(){
    int id, p, r;
    cin >> id >> p >> r;
    N++;

    reloadTime[id]= r;
    powerArr[id]= p;
    readyQ.push({p,id});
}

void getReady() {
    cin >> N;
    for (int i=0; i<N; i++){
        int id, p, r;
        cin >> id >> p >> r;
        reloadTime[id]= r;
        powerArr[id]= p;
        readyQ.push({p, id});
    }
}

void renew(){
    while (!reloadQ.empty()) {
        auto [time, Info]= reloadQ.top();

        if (time > currTime) break;

        reloadQ.pop();
        // 유령 데이터는 넣지 않음.
        if (Info.power != powerArr[Info.num]) continue;

        // cout << Info.power << " " << Info.num  << " 꺼내짐\n";
        readyQ.push(Info);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    for (int i=0; i<T; i++){
        currTime++;
        // reloadQ에서 매번 꺼내줘야 함.
        renew();

        int num;
        cin >> num;

        if (num==100) getReady();
        else if (num==200) addShip();
        else if (num==300) replaceShip();
        else if (num==400) attack();
    }

    return 0;
}