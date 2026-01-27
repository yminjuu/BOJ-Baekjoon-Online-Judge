#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   long N, k;
   cin >> N >> k;

   long i=1; long j=k; int ans=0;
   
   while (i<=j){
    long mid = (i+j)/2;

    long sum=0;
    for (int i=1; i<=N; i++){
        sum+= min(mid/i, N);
    }

        if (sum < k){
            i= mid+1;
        } else {
            j= mid-1;
            ans = mid;
   }
   }

   cout << ans;

   return 0;
}
