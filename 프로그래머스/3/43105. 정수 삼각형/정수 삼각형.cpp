#include <string>
#include <vector>
#include <climits>

using namespace std;
int dp[502][502];

int solution(vector<vector<int>> triangle) {
    int answer = INT_MIN;
    int N= triangle.size();
    
    dp[0][0]= triangle[0][0];
    dp[1][0]= dp[0][0]+ triangle[1][0];
    dp[1][1]= dp[0][0]+ triangle[1][1];
    for (int i=2; i<N; i++){
        for (int j=0; j<N; j++){
            // 맨 앞
            if (j==0) dp[i][j]= dp[i-1][0];
            
            // 맨 뒤
            else if (j==i) dp[i][j]= dp[i-1][i-1];
            
            else dp[i][j]= max(dp[i-1][j-1], dp[i-1][j]);
            
            dp[i][j] += triangle[i][j];
        }
    }
    
    // 최대 높이 인덱스 N-1, 노드 개수 N
    for (int i=0; i<=N; i++){
        answer = max(dp[N-1][i], answer);
    }
    
    return answer;
}