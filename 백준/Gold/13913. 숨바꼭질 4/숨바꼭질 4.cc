#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;
int times[100005]; // 해당 위치까지 도달하는 데에 걸리는 최소 시간을 저장
int path[100005];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, K;
    cin >> N >> K;
    fill(&times[0], &times[100001], INT_MAX);

    queue<int> q; 

    q.push(N); times[N]=0; path[N]= -1;
    
    while (!q.empty()){
        int currPos = q.front(); q.pop();
        int currTime = times[currPos];

        if (currPos==K) {
            cout << times[currPos] << "\n";
            break;
        }

        if (currPos+1 <=100000 && currTime+1 < times[currPos+1]) {
            times[currPos+1]= currTime+1;
            path[currPos+1] = currPos;
            q.push(currPos+1);
        }

        if (currPos>= 1 && currTime+1 < times[currPos-1]) {
            times[currPos-1]= currTime+1;
            path[currPos-1]= currPos;
            q.push(currPos-1);
        }

        if (currPos*2 <= 100000 && currTime+1 < times[currPos*2]){
            times[currPos*2]= currTime+1;
            path[currPos*2]= currPos;
            q.push(currPos*2);
        }

    }

    vector<int> ans; ans.push_back(K);
    
    int idx = K;
    while (true){
        int currPos= path[idx];
        
        if (currPos==-1) break;
        else {
            ans.push_back(currPos);
            idx= currPos;
        }
    }

    reverse(ans.begin(), ans.end());

    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

   return 0;
}