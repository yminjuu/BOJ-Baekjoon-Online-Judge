#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int solution(string s) {
    int totalLth = s.length();
    int answer = totalLth;
    
    int basisLth= s.length()/2; // 의미 있는 단위 최댓값: 절반값
    
    for (int lth = basisLth; lth>=1; lth--){
        int tmpLth= 0;
        // 현재 기준으로 삼는 단위의 길이 lth
        
        string baseStr= s.substr(0, lth);
        int startIdx=0;
        int repeatCnt=1;
        for (startIdx=lth ; startIdx+lth <= totalLth; startIdx+= lth){
            if (s.substr(startIdx, lth) == baseStr) {
                repeatCnt++;
            } else {
                if (repeatCnt==1) tmpLth+=lth; // 앞의 lth 만큼의 문자는 건너뜀
                else {
                    tmpLth+= (lth + to_string(repeatCnt).length());
                }
                
                // 초기화
                baseStr= s.substr(startIdx, lth);
                repeatCnt= 1;
            }
        }
        
        if (repeatCnt>1){
            // 반복됐었고 끝났다면
            tmpLth+= (lth + to_string(repeatCnt).length());
            tmpLth+= totalLth-startIdx;
        } else {
            // 앞에 반복이 없고 끝났다면
            tmpLth += lth;
            tmpLth += totalLth-startIdx;
        }
        
        answer = min(answer, tmpLth);
    }
    
    return answer;
}