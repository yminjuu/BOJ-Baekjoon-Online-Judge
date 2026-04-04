#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
using p = pair<int,int>;

#define x first
#define y second

int R, C;
int arr[21][21];
int ans =0;
int alphabet[26];
int visited[21][21];

int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};

void dfs(int x, int y, int path){
    ans = max(ans, path);
    for (int d=0; d<4; d++){
        int nextX= x+dx[d]; int nextY= y+dy[d];
        if (nextX<0 || nextY<0 || nextX>=R || nextY>=C) continue;

        if (alphabet[arr[nextX][nextY]]!=1 && !visited[nextX][nextY]) {
            alphabet[arr[nextX][nextY]]= 1;
            visited[nextX][nextY]= 1;
            dfs(nextX, nextY, path+1);
            alphabet[arr[nextX][nextY]]= 0;
            visited[nextX][nextY]= 0;
        }
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    cin >> R >> C;

    fill(&visited[0][0], &visited[20][20]+1, 0);

    for (int i=0; i<R; i++){
        string str;
        cin >> str;
        for (int j=0; j<C; j++){
            arr[i][j] = str.at(j)-'A';
        }
    }

    visited[0][0]= 1;
    alphabet[arr[0][0]]=1;
    dfs(0,0,1);

    cout << ans;

   return 0;
}
