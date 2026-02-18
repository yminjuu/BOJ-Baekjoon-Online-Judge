#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;

int strength[5][5];
long dp[100005][5][5];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    for (int i=0; i<100005; i++){
        for (int j=0; j<5; j++){
            for (int k=0; k<5; k++){
                dp[i][j][k]= LLONG_MAX;
            }
        }
    }

    for (int i=0; i<5; i++) strength[i][i]= 1;
    for (int i=1; i<5; i++) strength[0][i]= 2; 
    for (int i=1; i<5; i++){
        int a = i-1; if (a==0) a= 4;
        int b = i+1; if (b==5) b=1;
        strength[i][a]= 3;
        strength[i][b]= 3;
    }
    strength[2][4]= 4; strength[4][2]= 4;
    strength[1][3]= 4; strength[3][1]= 4; 


    dp[0][0][0]= 0;
    int idx=1;
    while (true){
        int dir;
        cin >> dir;
        if (dir==0) break;

        for (int i=0; i<5; i++){
            for (int j=0; j<5; j++){
                if (dp[idx-1][i][j]!=LLONG_MAX){
                    // 왼발 이동
                    if (dir!=j){
                        dp[idx][dir][j] = min(dp[idx-1][i][j] + strength[i][dir], dp[idx][dir][j]);
                    }

                    // 오른발 이동
                    if (dir!=i){
                        dp[idx][i][dir] = min(dp[idx-1][i][j] + strength[j][dir], dp[idx][i][dir]);
                    }
                }
            }
        }

        idx++;
    }

    long mn= LLONG_MAX;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            if (mn>dp[idx-1][i][j]) mn= dp[idx-1][i][j];
        }
    }

    cout << mn;

   return 0;
}
