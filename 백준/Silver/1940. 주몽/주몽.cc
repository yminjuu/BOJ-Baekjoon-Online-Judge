#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, cnt=0;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> N >> M;
   int a[N];
   for (int i=0; i<N; i++){
        cin >> a[i];
   }

   for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
        if (a[i]+a[j]==M) cnt++;
    }
   }

   cout << cnt;

   return 0;
}