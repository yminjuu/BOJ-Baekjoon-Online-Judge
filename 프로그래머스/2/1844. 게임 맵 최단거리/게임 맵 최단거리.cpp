#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;
using p = pair<int,int>;

int ans[102][102]; // 이 좌표까지 가는 최솟값
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};

int solution(vector<vector<int> > maps)
{
    int n = maps.size(); int m = maps[0].size();
    fill(&ans[0][0], &ans[101][101], INT_MAX);
    
    // 시작 (0,0) 목표 (n-1, m-1)
    
    queue<p> q;
    q.push({0,0});
    ans[0][0]=1;

    while (!q.empty()){
        int x = q.front().first; int y= q.front().second;
        q.pop();
        
        if (x==n-1 && y==m-1) {
            continue;
        }
        
        for (int i=0; i<4; i++){
            int newX= x+dx[i]; int newY= y+dy[i];
            if (newX>=0 && newX <n && newY>=0 && newY<m && maps[newX][newY]){
                if (ans[newX][newY] <= ans[x][y]+1) continue; 
                
                // 이 부분을 다시 보기 (안 그럼 시간 초과)
                
                ans[newX][newY]= min(ans[x][y]+1, ans[newX][newY]);
                q.push({newX, newY});
            }
        }
    }
    
    if (ans[n-1][m-1]==INT_MAX) return -1;
    else return ans[n-1][m-1];
}