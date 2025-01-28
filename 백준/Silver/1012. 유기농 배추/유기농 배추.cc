#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, M, N, K, a,b;
int B[52][52]={0};
int checkArr[4][4]= { {0,0,1,-1}, {1, -1, 0,0}};

void check(int m, int n){
    B[m][n]=0;
    for (int k=0; k<4; k++){
            if (B[m+checkArr[0][k]][n+checkArr[1][k]]){
                check(m+checkArr[0][k], n+checkArr[1][k]);
                B[m+checkArr[0][k]][n+checkArr[1][k]]=0;
            }
    }
    return;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> T;
   while (T--){
    cin >> M >> N >> K;
    int sum=0; 
    
    for (int i=0; i<K; i++){
        cin >> a >> b;
        B[a+1][b+1]=1;
    }

    for (int i=1; i<=M; i++){
        for (int j=1; j<=N; j++){
            if (B[i][j]) {check(i,j); sum++;};
        }
    }

    cout << sum << endl;
   }

   return 0;
}
