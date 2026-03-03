#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

using namespace std;
int N;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    cin >> N;
    vector<int> vec;

    for (int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), greater<int>()); // 내림차순 정렬

    long mx = LLONG_MIN; long total=1;
    for (int i=0; i<N; i++){
        long tmp = vec[i]*total;
        mx = max(tmp, mx);
        
        total++;
    }

    cout << mx;

   return 0;
}
