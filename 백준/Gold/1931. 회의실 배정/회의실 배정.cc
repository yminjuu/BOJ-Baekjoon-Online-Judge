#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef pair<int,int> Meet;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, ans=0;
   cin >> N;
    vector<Meet> meetings(N);

    for (int i=0; i<N; i++){
        cin >> meetings[i].second >> meetings[i].first;
    }
    sort(meetings.begin(), meetings.end());

    int time=0;
    for (int i=0; i<N; i++){
        if (time<=meetings[i].second){
            ans++;
            time= meetings[i].first;
        }
    }

    cout << ans;

   return 0;
}
