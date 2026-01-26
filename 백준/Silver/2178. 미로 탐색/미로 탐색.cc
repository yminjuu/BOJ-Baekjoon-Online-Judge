#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M;
char c;
int arr[102][102] = {
    0,
};
int dist[102][102] = {
    0,
};
queue<pair<int, int>> q;

int DFS(int x, int y)
{
    while (!q.empty())
    {
        q.pop();
        if (arr[x + 1][y] && !dist[x + 1][y])
        {
            q.push(make_pair(x + 1, y));
            dist[x + 1][y] = dist[x][y] + 1;
        }
        if (arr[x][y + 1] && !dist[x][y + 1])
        {
            q.push(make_pair(x, y + 1));
            dist[x][y + 1] = dist[x][y] + 1;
        }
        if (arr[x - 1][y] && !dist[x - 1][y])
        {
            q.push(make_pair(x - 1, y));
            dist[x - 1][y] = dist[x][y] + 1;
        }
        if (arr[x][y - 1] && !dist[x][y - 1])
        {
            q.push(make_pair(x, y - 1));
            dist[x][y - 1] = dist[x][y] + 1;
        }
        x = q.front().first;
        y = q.front().second;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> c;
            arr[i][j] = c - '0';
        }
    }

    q.push(make_pair(1, 1));
    dist[1][1] = 1;
    DFS(1,1);

    cout << dist[N][M];
    return 0;
}