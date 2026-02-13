#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int D[15][15]; // 0 초기화

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int T;
    cin >> T;

    for (int i=1; i<=14; i++){
        D[0][i]= i; // 0층의 i호에는 i명 거주
        D[i][0]= 0; // 0호는 0명 거주
    }

    for (int i=1; i<=14; i++){
        for (int k=1; k<=14; k++){
            D[i][k] = D[i-1][k] + D[i][k-1];
        }
    }

    while (T--){
        int a,b;
        cin >> a >> b;
        cout << D[a][b] << "\n";
    }

   return 0;
}
