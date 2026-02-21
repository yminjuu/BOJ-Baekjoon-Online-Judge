#include <string>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
using p = pair<int, int>;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, long> mp; // 차량 번호 별 들어와있던 시간 : 기본 번호 오름차순
    map<string, string> tmp; // 입차 시간을 담기 위한 임시
    for (int i=0; i<records.size(); i++){
        string str = records[i];
        
        string time= str.substr(0, 5); // 05:34
        string carNum= str.substr(6, 4);
        
        // 이미 입차됐고 출차라면
        if (tmp.find(carNum)!=tmp.end()) { 
            int afterTime = stoi(time.substr(0,2))*60 + stoi(time.substr(3));
            int prevTime = stoi(tmp[carNum].substr(0,2))*60 + stoi(tmp[carNum].substr(3));
            int timeDiff= afterTime- prevTime;
            if (mp.find(carNum)!=mp.end()){
                mp[carNum]+= timeDiff;
            } else {
                mp[carNum]= timeDiff; // 분 단위 저장
            }
            tmp.erase(carNum);
        } else {
            // 새로 입차라면
            tmp[carNum] = time; // 입차
        }
    }
    
    // 자동 반복문 복습할 것
    for (auto& [key, value] : tmp){
        // 아직 남아있다면 23:59 기준으로 남은 시간 계산
        int afterTime = 60*23 + 59; 
        int prevTime = stoi(value.substr(0,2))*60 + stoi(value.substr(3));
        int timediff= afterTime- prevTime;
        
        if (mp.find(key)!=mp.end()) mp[key]+= timediff;
        else mp[key]= timediff;
    }
    
    for (auto& [key, value] : mp){
        int leftMinute = value - fees[0]; // 남은 계산해야 하는 시간
        int cost = fees[1]; // 기본 요금
        
        if (leftMinute>0){
            cost += ceil((float)leftMinute / fees[2]) * fees[3];
        }
        answer.push_back(cost);
    }
    
    return answer;
}