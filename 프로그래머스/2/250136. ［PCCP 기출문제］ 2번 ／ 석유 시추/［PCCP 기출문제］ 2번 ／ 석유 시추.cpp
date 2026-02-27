#include <string>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>

using namespace std;

vector<vector<int>> gland; // 인덱스 표기
vector<int> sizes; // 덩어리 인덱스마다 크기 표시
set<int> sets[502]; // 덩어리마다 포함하고 있는 열의 집합, 1부터 시작
int n, m, sz=0;
int visited[502][502];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int q[502];

void dfs(int x, int y, int idx){
    for (int i=0; i<4; i++){
        int newX= x+dx[i]; int newY= y+dy[i];
        if (newX>=0 && newX<n && newY>=0 && newY<m && !visited[newX][newY] && gland[newX][newY]){
            sets[newY].insert(idx); // 새로운 열 추가
            visited[newX][newY]= 1;
            sz++;
            dfs(newX, newY, idx);
        }
    }
}

// 0이면 빈 땅, 1이면 석유가 있는 땅
int solution(vector<vector<int>> land) {
    gland= land;
    int answer = 0;
    
    n= land.size(); m= land[0].size();
    
    int idx= 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (!visited[i][j] && land[i][j]) {
                visited[i][j]=1;
                sz= 1;
                dfs(i,j, idx);
                sets[j].insert(idx); // 열 번호에 덩어리 번호 삽입
                sizes.push_back(sz); 
                idx++;
            }
        }
    }
    
    int mx = INT_MIN; int mxIdx= 0;
    // 모든 열에 대하여
    for (int i=0; i< m; i++){
       for (auto a : sets[i]){
           q[i]+= sizes[a];
       }
        if (mx < q[i]) {
            mx = q[i];
        }
    }
    
    answer=  mx;
    
    return answer;
}