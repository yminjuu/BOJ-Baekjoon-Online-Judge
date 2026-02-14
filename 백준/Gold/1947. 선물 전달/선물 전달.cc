#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
static vector<long> D;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;

    cin >> N;
    D.resize(N+1);

    D[2]= 1;
    D[1]= 0;

    for (int i=3; i<=N; i++){
        D[i] = (i-1) * (D[i-2]+D[i-1]);
        D[i] %= 1000000000;
    }

    cout << D[N];
    return 0;
}
