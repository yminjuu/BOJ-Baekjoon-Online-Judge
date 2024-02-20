#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, hCnt = 0, cnt = 0;
char c;
int arr[27][27] = {
    0,
};
queue<pair<int, int>> q;
priority_queue<int, vector<int>, greater<int>> pq;

void BFS(int x, int y)
{
    hCnt++;
    q.pop();

    if (arr[x - 1][y]){
        q.push(make_pair(x - 1, y));
        arr[x-1][y] = 0;
    }
    if (arr[x][y - 1]){
        q.push(make_pair(x, y - 1));
        arr[x][y-1] = 0;
    }
    if (arr[x + 1][y]){
        q.push(make_pair(x + 1, y));
        arr[x+1][y] = 0;
    }
    if (arr[x][y + 1]){
        q.push(make_pair(x, y + 1));
        arr[x][y+1] = 0;
    }

    if (!q.empty())
        BFS(q.front().first, q.front().second);
    else return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> c;
            arr[i][j] = c-'0';
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j])
            {
                arr[i][j]=0;
                hCnt = 0;
                cnt++;
                q.push(make_pair(i, j));
                BFS(i, j);
                pq.push(hCnt);
            }
        }
    }

    cout << cnt;
    while(!pq.empty()){
        cout << "\n";
        cout << pq.top();
        pq.pop();
    }

    return 0;
}