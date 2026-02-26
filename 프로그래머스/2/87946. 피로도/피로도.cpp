#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int answer = 0;
int N;
using p = pair<int,int>;

int visited[10];
vector<p> dungeon; 

void dfs(int n, int cnt, int currStr){
    answer = max(cnt, answer);
    
    for (int i=0; i<N; i++){
        int minStr = dungeon[i].first; int spendStr = dungeon[i].second;
        if (!visited[i] && currStr>= minStr){
            visited[i]= 1;
            dfs(i, cnt+1, currStr-spendStr);
            visited[i]=0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    N = dungeons.size();
    for (int i=0; i<N; i++){
        dungeon.push_back({dungeons[i][0], dungeons[i][1]});
    }
    
    for (int i=0; i<N; i++){
        visited[i]= 1;
        if (k>= dungeon[i].first) dfs(i, 1, k- dungeon[i].second); // i부터 시작하는 dfs
        visited[i]= 0;
    }
    
    return answer;
}