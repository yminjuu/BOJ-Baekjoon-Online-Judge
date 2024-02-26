#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, E, a, b, c, essA, essB, cnt1 = 0, cnt2 = 0, k;
vector<pair<int, int>> edge[802];
int dest[802];

void shortest_path(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill_n(dest, N + 1, 987654321);
    dest[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        pq.pop();
        for (int i = 0; i < edge[start].size(); i++)
        {
            k = edge[start].at(i).first;
            if (dest[k] > dest[start] + edge[start].at(i).second)
            {
                dest[k] = dest[start] + edge[start].at(i).second;
                pq.push(make_pair(dest[k], k));
            }
        }
        start = pq.top().second;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }
    cin >> essA >> essB;

    shortest_path(1);
    cnt1 += dest[essA]; // 1 -> essA
    cnt2 += dest[essB]; // 2 > essB

    shortest_path(essA);
    cnt1 += dest[essB]; // essA->essB
    cnt2 += dest[N];    // essA-> end

    shortest_path(essB);
    cnt1 += dest[N];    // essB->end
    cnt2 += dest[essA]; // essB->essA

    k = min(cnt1, cnt2);
    k = min(987654321, k);
    if (k == 987654321 || k < 0)
        cout << "-1";
    else
        cout << k;
    return 0;
}