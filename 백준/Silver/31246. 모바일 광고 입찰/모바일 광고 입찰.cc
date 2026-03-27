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
   
   int N, K;
    cin >> N >> K;

    vector<long> diffs;
    for (int i=0; i<N; i++){
        long a,b;
        cin >> a >> b;
        if (a>=b) K--;
        else diffs.push_back(b-a);
    }

    if (K<=0) {cout << 0; return 0;}
    sort(diffs.begin(), diffs.end());

    cout << diffs[K-1];

   return 0;
}
