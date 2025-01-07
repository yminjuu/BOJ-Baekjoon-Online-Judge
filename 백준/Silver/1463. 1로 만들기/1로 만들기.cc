#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;

int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> N;
   int memo[1000001] = {0};

    for (int i=2; i<N+1; i++){
        memo[i]= memo[i-1]+1;

        if (i%2==0) memo[i]= min(memo[i], memo[i/2]+1);

        if (i%3==0) memo[i]= min(memo[i], memo[i/3]+1);
    }

   cout << memo[N];

   return 0;
}