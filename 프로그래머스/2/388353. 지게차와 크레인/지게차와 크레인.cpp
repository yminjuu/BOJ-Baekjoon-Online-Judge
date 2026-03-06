#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;
using p = pair<int, int>;

int N,M;
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};
string arr[52][52];

vector<p> find(string s){
    vector<p> ans;
    stack<p> stck;    
    
    int visited[N][M];
    fill(&visited[0][0], &visited[N-1][M-1]+1, 0);
    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (i!=0 && j!=0 && i!=N-1 && j!=M-1) continue;
            if (arr[i][j]=="") stck.push({i,j});
            if (arr[i][j]==s){
                ans.push_back({i,j});
                visited[i][j]= 1;
            }
        }
    }
    
    // 빈 문자열만 dfs 형태로 탐색
    while (!stck.empty()){
        auto [x,y]= stck.top(); stck.pop();
        visited[x][y]= 1;
        
        for (int d=0; d<4; d++){
            int nextX = x+dx[d]; int nextY= y+dy[d];
            
            if (nextX>=0 && nextY>=0 && nextX<N && nextY<M && !visited[nextX][nextY]){
                visited[nextX][nextY]= 1;
                if (arr[nextX][nextY]==s) ans.push_back({nextX, nextY}); 
                // 해당 문자열을 찾음 (더이상 갈 수는 없음)
                
                if (arr[nextX][nextY]==""){
                    stck.push({nextX, nextY});
                }
            }
        }
    }
    return ans;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    N= storage.size(); M= storage[0].size();
    
    string tmp;
    for (int i=0; i<N; i++){
        tmp= storage[i];
        for (int j=0; j<tmp.size(); j++){
            arr[i][j]= tmp.substr(j, 1);
        }
    }
    
    for (int i= 0; i< requests.size(); i++){
        string reqStr= requests[i];
        
        if (reqStr.length()==1) {
            // 지게차
            vector<p> foundStrings= find(reqStr);
            
            // 찾은 문자열들을 ""로 바꾼다
            for (int j=0; j<foundStrings.size(); j++){
                auto [x,y]= foundStrings[j];
                arr[x][y]= "";
            }
        } else {
            reqStr = reqStr.substr(0, 1);
            // 크레인
            for (int j=0; j<N; j++){
                for (int k=0; k<M; k++){
                    if (arr[j][k]==reqStr) {arr[j][k]= ""; }// 전부 꺼낸다
                }
            }
        }
    }
    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (arr[i][j]!="") answer++;
        }
    }
    
    return answer;
}