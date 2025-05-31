#include <vector>
#include <queue>

using namespace std;

int visited[102][102]= {0}; 
// 한번 갔던 길이 불가능하다고 판단됐다면, 다시 방문해서 또다시 판단할 필요 없음

int solution(vector<vector<int> > maps)
{
   int x=0, y=0;
    int ySize = maps.size(); int xSize= maps[0].size();
    queue<pair<pair<int,int>, int>> stck;
    int basisArr[4][2] = {{1,0}, {0,1}, {-1, 0}, {0, -1}};
    
    stck.push({{0,0}, 1});
    visited[0][0]=1;
    while (!stck.empty()){
        x= stck.front().first.first; y=stck.front().first.second;
        int cnt= stck.front().second;
        stck.pop();
        
        if (x==xSize-1 && y==ySize-1) return cnt;
        
        // 그 후에 갈 길은 stck에 넣어줌
        // 갈 수 없는 길, 이미 방문했던 길은 제외한다.
        for (int i=0; i<4; i++){
            int nx= x + basisArr[i][0];
            int ny= y + basisArr[i][1];
            
            if (nx>=0 && nx<xSize && ny>=0 && ny<ySize && !visited[ny][nx] && maps[ny][nx]) {
                visited[ny][nx]= 1;
                stck.push({{nx, ny}, cnt+1});
        }
            }
        }
    return -1;
}