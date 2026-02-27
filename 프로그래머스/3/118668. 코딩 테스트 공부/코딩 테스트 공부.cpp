#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
vector<vector<int>> gProblems;

int answer= INT_MAX;
int n;
int maxAlp, maxCop;
int alpRwd, copRwd;
int dp[1000][1000]; // 최소 시간

void find(int alp, int cop){
    if (alp>= maxAlp && cop>= maxCop) {
        answer = min(answer, dp[alp][cop]); 
        return;
    }
    
    // 1. 알고력 1 높이기
    if (dp[alp+1][cop] > dp[alp][cop]+1 && alp+1 <= maxAlp){
        if (dp[alp+1][cop] >dp[alp][cop]+1){
            dp[alp+1][cop] = dp[alp][cop]+1;
            find(alp+1, cop);   
        }
    }
    
    // 2. 코딩력 1 높이기
    if (dp[alp][cop+1] > dp[alp][cop]+1 && cop+1 <= maxCop){
        if (dp[alp][cop+1] > dp[alp][cop]+1){
            dp[alp][cop+1] = dp[alp][cop]+1;
            find(alp, cop+1);   
        }
    }
    
    // 3. 문제 풀기
    for (int i=0; i<gProblems.size(); i++){
        
        int newAlp = alp + gProblems[i][2];
        int newCop= cop + gProblems[i][3];
        
        if (newAlp >= maxAlp) newAlp= maxAlp;
        if (newCop >= maxCop) newCop= maxCop;
        
        if ((dp[alp][cop]+gProblems[i][4] < dp[newAlp][newCop]) && alp>= gProblems[i][0] && cop >= gProblems[i][1]) {
            dp[newAlp][newCop] = dp[alp][cop] + gProblems[i][4];
            find(newAlp, newCop);
        }
    }
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    gProblems =problems;
    n= problems.size();
    fill(&dp[0][0], &dp[999][999]+1, INT_MAX);
    
    for (int i=0; i<n; i++){
        maxAlp = max(maxAlp, problems[i][0]);
        maxCop = max(maxCop, problems[i][1]);
    }
    
    // maxAlp, maxCop를 달성할 수 있는 최소 시간을 구해야 한다.
    
    dp[alp][cop]= 0; // 이미 도달
    find(alp, cop);
    
    return answer;
}