#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

string str;
map<string,int> cnt;

void dfs(int basis, string current) {
    if (basis==str.length()){
        cnt[current]++;
        return;
    }
    
    dfs(basis+1, current+str[basis]); // 포함함
    dfs(basis+1, current); // 건너뜀
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int i=0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end()); // sort는 문자열 반환하지 않음
        
        str = orders[i];
        // 모든 조합에 대해 map에 저장
        dfs(0, "");
    }
    
    for (int lth: course){
        // 단품 메뉴 구성 개수별로 최댓값 구하기
        int maxCnt= 0;
        for (auto [key,value]: cnt) {
            if (key.length() == lth && value > maxCnt) maxCnt= value;   
        }
        
        if (maxCnt<2) continue;
        // 최댓값과 동일한 메뉴 구성을 answer에 넣기
        for (auto [key, value]: cnt){
            if (key.length() == lth && value==maxCnt) answer.push_back(key);
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}