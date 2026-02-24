#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int a,b;
int n;
int ans=0;
vector<int> family[102];

// a를 통해 b를 찾는다
int BFS(int a){
    ans= -1;
    queue<pair<int,int>> q;
    int visited[n+2];
    fill(&visited[0], &visited[n+1], 0);

    visited[a]= 1;
    q.push({a, 0});

    while (!q.empty()){
        int curr = q.front().first; 
        int currCost= q.front().second;
        
        q.pop();

        if (curr==b) {
            ans = currCost;
            return currCost;
        }
        
        for (int i=0; i<family[curr].size(); i++){
            if (visited[family[curr][i]]) continue;
            q.push({family[curr][i], currCost+1});
            visited[family[curr][i]]= 1;
        }
    }

    if (ans==0) return -1;
    return ans;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    cin >> n >> a >> b;

    int m;
    cin >> m;
    while (m--){
        int x, y;
        cin >> x >> y;
        family[x].push_back(y);
        family[y].push_back(x);
    }

    ans = BFS(a);

    cout << ans;

   return 0;
}
