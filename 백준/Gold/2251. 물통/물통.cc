#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int sender[6]= {0,0,1,1,2,2};
int receiver[6] = {1,2,0,2,0,1};
int capacity[3];
bool visited[201][201][201];
vector<int> ans;

void DFS(int a, int b, int c){
    visited[a][b][c]= true;
    if (a==0) ans.push_back(c);

    for (int i=0; i<6; i++){
        int currWater[3] = {a,b,c};
        
        int sendWater = currWater[sender[i]];
        if (sendWater+currWater[receiver[i]] > capacity[receiver[i]]){
            // 용량 넘치면
            sendWater = capacity[receiver[i]]- currWater[receiver[i]];
        }

        // 물 보내기
        currWater[sender[i]]-= sendWater;
        currWater[receiver[i]]+= sendWater;

        if (!visited[currWater[0]][currWater[1]][currWater[2]]) {
            // 방문하지 않았다면
            DFS(currWater[0], currWater[1], currWater[2]);
        }
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> capacity[0] >> capacity[1] >> capacity[2];

    DFS(0,0,capacity[2]);

    sort(ans.begin(), ans.end());
    for (int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }

   return 0;
}
