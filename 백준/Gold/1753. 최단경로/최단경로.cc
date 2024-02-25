#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

#define MAX 20002

int V, E, K, u, v, w;
vector<pair<int, int>> gph[MAX];


struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int ret_min(int a, int b, int idx)
{
    if (a <= b)
        return a;
    else
    {
        pq.push(make_pair(idx, b));
        return b;
    }
}

void shortest_Path(int k)
{
    int visited[V+1] = {0,};
    
    int dest[V+1];
    fill_n(dest, V+1, 987654321);
    dest[k] = 0;

    while (!pq.empty())
    {
        pq.pop();
        if (!visited[k]){
            for (int i = 0; i < gph[k].size(); i++)
            {
                int idx = gph[k].at(i).first;
                dest[idx] = ret_min(dest[idx], dest[k] + gph[k].at(i).second, idx);
            }
        }
        visited[k]= 1;
        k = pq.top().first;
    }
    
    for (int i = 1; i <= V; i++)
    {
        if (dest[i] == 987654321)
            cout << "INF"
                 << "\n";
        else
            cout << dest[i] << "\n";
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E >> K;

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        gph[u].push_back(make_pair(v, w));
    }

    pq.push(make_pair(K, 0));
    shortest_Path(K);

    return 0;
}