#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define INF 987654321
int dp[1002][52];

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    temperature+=10; t1+= 10; t2+=10; // 10 오프셋
    
    // dp 배열 초기화
    fill(&dp[0][0], &dp[1001][51]+1, INF);
    
    // 첫 날
    dp[0][temperature]= 0; // 전력 소비 없음
    
    for (int i=0; i<onboard.size()-1 ; i++){
        // 모든 가능한 온도에 대하여
        for (int tmp=0; tmp<=50; tmp++){
            if (dp[i][tmp]==INF) continue;
            
            // (1) 에어컨 끄기 => 전력 소모 없음, 외부 온도에 맞춰짐
                //  조건: (i+1)분에 손님이 타있으면 최적 온도 범위 내여야 함.
            if (tmp<temperature && !(onboard[i+1] && tmp+1>t2) && tmp+1<=50) dp[i+1][tmp+1] = min(dp[i][tmp], dp[i+1][tmp+1]);
            else if (tmp>temperature && !(onboard[i+1] && tmp-1<t1) && tmp-1>=0) dp[i+1][tmp-1] = min(dp[i][tmp], dp[i+1][tmp-1]);
            else if (tmp==temperature && !(onboard[i+1] && (tmp>t2 || tmp<t1))) dp[i+1][tmp]= min(dp[i][tmp], dp[i+1][tmp]);
            
            // (2) 온도 변경하기
            if ((!onboard[i+1] && (tmp+1<=t2)) || (onboard[i+1] && (tmp+1>=t1 && tmp+1<=t2))){
                dp[i+1][tmp+1] = min(dp[i][tmp] + a, dp[i+1][tmp+1]);
            } 
            if ((!onboard[i+1] && (tmp-1>=t1)) || (onboard[i+1] && (tmp-1>=t1 && tmp-1<=t2))){
                dp[i+1][tmp-1] = min(dp[i][tmp]+ a, dp[i+1][tmp-1]);
            }
            
            // (3) 온도 유지하기 (희망온도==실내온도)
            if (!onboard[i+1] || (onboard[i+1] && (t1 <= tmp && tmp<=t2))){
                // 다음에 손님이 안 타있거나
                // 손님이 타있지만 온도 유지해도 될 때
                dp[i+1][tmp] = min(dp[i][tmp] + b, dp[i+1][tmp]);
            }
        }
    }
    
    int mn = INF;
    for (int i=0; i<=50; i++){
        int lastMinute= onboard.size()-1;
        mn = min(mn, dp[lastMinute][i]);
    }
    
    return mn;
}