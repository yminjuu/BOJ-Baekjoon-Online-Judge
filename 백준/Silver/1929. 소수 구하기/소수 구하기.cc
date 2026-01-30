#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> M >> N;

    if (M==1) M++;
    vector<bool> vec(N+1, false);
    
    for (int i=2; i<=sqrt(N); i++){
        if (!vec[i]){
            for (int j=i*i; j<=N; j++){
                if (j%i==0 && !vec[j]) vec[j]= true;
            }   
        }
    }

    for (int i=M; i<=N; i++){
        if (!vec[i]) cout << i << "\n";
    }

   return 0;
}
