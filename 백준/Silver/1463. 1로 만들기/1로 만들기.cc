#include <iostream>
#include <vector>

using namespace std;
int N;
int memo[1000001]= {0};

int DP(int k){
    if (k<=3) return memo[k];

    int min=1000000;

    if (!memo[k-1]) memo[k-1]= DP(k-1);
    min = memo[k-1];

    if (k%3==0) {
        if (!memo[k/3]) memo[k/3]= DP(k/3); 
        if (min > memo[k/3]) min = memo[k/3];
    }

    if (k%2==0) {
        if (!memo[k/2]) memo[k/2]= DP(k/2);
        if (min > memo[k/2]) min = memo[k/2];
    }

    memo[k]= min+1;
    return min+1;
}

int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   memo[1]= 0; memo[2]=1; memo[3]=1;

   cin >> N;

   DP(N);

   cout << memo[N];

   return 0;
}