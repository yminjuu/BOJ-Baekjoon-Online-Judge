#include <iostream>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

using ll =long long;

struct lightllerval{
    ll startPos, endPos, dist;
    bool operator < (const lightllerval& tmp) const {
        if (dist==tmp.dist) return startPos > tmp.startPos;
        else return dist < tmp.dist; // pq는 반대
    }
};

ll N, M;
set<ll> alivePos; // 살아 있는 가로등만 관리
map<ll, ll> posToIdx; // 위치 -> 인덱스
map<ll, ll> idxToPos; // 인덱스 -> 위치
priority_queue<lightllerval> pq;

void add(){
    ll startPos, endPos, dist;
    // 가장 간격이 큰 부분에 넣기
    while (!pq.empty()){
    lightllerval top = pq.top();
    pq.pop();

    auto itr = alivePos.find(top.startPos);
    // 1. 왼쪽 끝점이 아직 살아있는지 확인
    // 2. 그 다음 가로등이 여전히 top.endPos인지 확인
    if (itr != alivePos.end() && next(itr) != alivePos.end() && *next(itr) == top.endPos) {
        startPos = top.startPos;
        endPos = top.endPos;
        dist = top.dist;
        break;
    }
}

    M++;
    ll nextPos = (startPos+endPos+1)/ 2; // 오류수정1: float 없이 반올림
    alivePos.insert(nextPos);
    pq.push({startPos, nextPos, nextPos-startPos});
    pq.push({nextPos, endPos, endPos-nextPos});
    posToIdx[nextPos]= M;
    idxToPos[M]= nextPos;
}

void remove(ll d){
    // 제거하기 이전에 나의 prev와 next를 이어줘야 한다!
    auto itr = alivePos.find(idxToPos[d]);
    pq.push({*prev(itr), *next(itr), *next(itr)- *prev(itr)});
    alivePos.erase(idxToPos[d]); // set에서 제거한다.
}

void getR(){
    ll r;
    ll dist;
    // 1. 유효한 가로등에 대한 최대 간격
    while (!pq.empty()){
        ll startPos= pq.top().startPos;
        ll endPos= pq.top().endPos;
        dist= pq.top().dist;

        auto itr = alivePos.find(startPos);
        if (itr==alivePos.end() || *next(itr)!= endPos) {
            pq.pop();
            continue; 
        }// 둘 중 하나라도 삭제됐다면
        else {
            r= dist;
            break;
        }
    }

    // 2. set의 맨 앞 - 1
    r= max(r, (*alivePos.begin()-1)*2); // 맨 앞 원소

    // 3. N - set의 맨 뒤 
    r= max(r, (N- *prev(alivePos.end()))*2); // 맨 뒤 원소

    cout << r << endl;
}

int main() {
    ll Q;
    cin >> Q;

    ll q;
    cin >> q;
    cin >> N >> M;
    for (ll i=1; i<=M; i++){
        ll pos;
        cin >> pos;

        alivePos.insert(pos);
        auto it = alivePos.find(pos);
        posToIdx[pos]= i;
        idxToPos[i]= pos;
        if (i!=1) pq.push({*prev(it), pos, pos- *prev(it)});
    }
    Q--;

    while (Q--){
        ll next;
        cin >> next;
        if (next==200){
            add();
        } else if (next==300){
            ll D;
            cin >> D;
            remove(D);
        } else {
            getR();
        }
    }

    return 0;
}