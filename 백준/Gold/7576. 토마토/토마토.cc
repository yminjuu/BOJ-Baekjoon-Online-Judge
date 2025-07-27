#include <iostream>
#include <queue>
using namespace std;
int M, N, x, y, tmpX, tmpY;
int arr[1002][1002];
int day[1002][1002];
int xArr[4] = {1, -1, 0, 0};
int yArr[4] = {0, 0, 1, -1};
int mn=0;
queue<pair<int,int> > q;

int BFS()
{
    while (!q.empty()){
        x= q.front().first; y=q.front().second;   
        q.pop();

         for (int i = 0; i < 4; i++)
        {
            tmpX = x + xArr[i];
            tmpY = y + yArr[i];
            if (day[tmpX][tmpY]==-1){
                if (arr[tmpX][tmpY]==0){
                    mn= day[x][y]+1;
                    q.push(make_pair(tmpX,tmpY));
                    day[tmpX][tmpY]= mn;
                }
                else day[tmpX][tmpY]==-2;
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    fill(&day[0][0], &day[1002][1002], -2);

    int k=0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j]==1) {
                day[i][j]=0;
                q.push(make_pair(i,j));
                continue;
            }
            if (arr[i][j]==0) k=1;
            day[i][j] = -1;
        }
    }
    
    if (!q.empty()) BFS();
    else {
        if (k==1)
            cout << -1;
        else
            cout << 0;
        return 0;
    }

    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            if (day[i][j]==-1 && arr[i][j]==0) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << mn;
    return 0;
}