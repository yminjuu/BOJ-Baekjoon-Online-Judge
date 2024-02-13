#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, tm;
int val[11];

struct Time
{
    int index;
    int time;
};

struct cmp
{
    bool operator()(Time a, Time b)
    {
        return a.time > b.time;
    }
};

priority_queue<Time, vector<Time>, cmp> pq;
// priority_queue 선언: 자료형, 구조체, 비교함수 순서

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        Time T;
        cin >> tm;
        T.time = tm;
        pq.push(T);
    }

    int sum = 0;
    int fnt = 0;

    while (!pq.empty())
    {
        Time T = pq.top();
        pq.pop();
        sum += fnt + T.time;
        fnt += T.time;
    }
    cout << sum;

    return 0;
}