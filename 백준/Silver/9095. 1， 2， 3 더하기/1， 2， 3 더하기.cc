#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, n;
int DP[11]= {0};

int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> T;

   DP[1]= 1;
   DP[2]= 2;
   DP[3]= 4;

   for (int i=4; i<=10 ; i++) DP[i]= DP[i-1] + DP[i-2] + DP[i-3];
   
   for (int i=0; i<T; i++) {
    cin >> n;
    cout << DP[n] << "\n";
   }

   return 0;
}