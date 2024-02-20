#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arr[100001];
int visited[100001] = {
    0,
};
int N, M, R, u, v, cnt = 0;

void DFS(int r)
{
    visited[r] = ++cnt;
    for (int i = 0; i < arr[r].size(); i++)
    {
        int k = arr[r].at(i);
        if (!visited[k])
        {
            visited[k] = 1;
            DFS(k);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> R;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
        sort(arr[i].begin(), arr[i].end());
    DFS(R);

    for (int i = 1; i <= N; i++)
    {
        cout << visited[i] << "\n";
    }
    return 0;
}