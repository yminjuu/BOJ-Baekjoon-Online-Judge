#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N;
long ans = 0;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N;
    long zeros[N+1];
    long ones[N+1];

    zeros[1]=0; ones[1]=1;
    for (int i=2; i<=N; i++){
        zeros[i]= (zeros[i-1]+ones[i-1]);
        ones[i] = zeros[i-1];
    }

    cout << zeros[N]+ones[N];


   return 0;
}