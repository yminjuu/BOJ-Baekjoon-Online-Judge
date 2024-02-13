#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, srt, en;
int val[11];

struct Meet
{
    int start;
    int end;
};

struct cmp
{
    bool operator()(Meet a, Meet b)
    {
        if (a.end == b.end)
            return a.start > b.start;
        return a.end > b.end;
    }
};

priority_queue<Meet, vector<Meet>, cmp> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        Meet M;
        cin >> srt >> en;
        M.start = srt;
        M.end = en;
        pq.push(M);
    }

    int cnt = 0;
    int curr = 0;
    Meet M;
    while (!pq.empty())
    {
        M = pq.top();
        pq.pop();
        if (M.start >= curr)
        {
            cnt++;
            curr = M.end;
        }
    }

    cout << cnt;

    return 0;
}