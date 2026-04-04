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

int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};

// 비트마스킹 활용 DFS
// 방문배열 필요 X
void dfs(int x, int y, int alphabet_bit, int path){
    ans = max(path, ans);
    for (int d=0; d<4; d++){
        int newX= x+dx[d];
        int newY= y+dy[d];
        if (newX<0 || newY<0 || newX>=R || newY>=C) continue;

        if (!(alphabet_bit & (1 << arr[newX][newY]))){
            dfs(newX, newY, alphabet_bit | (1 << arr[newX][newY]), path+1);
        }
    }
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    cin >> R >> C;

    for (int i=0; i<R; i++){
        string str;
        cin >> str;
        for (int j=0; j<C; j++){
            arr[i][j] = str.at(j)-'A';
        }
    }

    int initial_bit = (1 << arr[0][0]);
    dfs(0,0, initial_bit, 1);

    cout << ans;

   return 0;
}
