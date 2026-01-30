#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;
int arr[1001000]; // 초깃값 0
int ans[1001000];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   long long mn, mx;
    cin >> mn >> mx;

    for (long long i=2; i<=ceil(sqrt(mx)); i++){
        long long powed = i*i; // 제곱수
        
        long long startPoint = mn/powed;
        if (mn%powed!=0) startPoint++;
        
        for (long long j=startPoint*powed; j<=mx; j+=powed){
            ans[j-mn]=1;
        }
    }

    int ansInt=0;
    for (int i=0; i<mx-mn+1; i++){
        if (ans[i]==0) ansInt++;
    }
    cout << ansInt;

   return 0;
}
