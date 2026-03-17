#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

#define x first
#define y second

using namespace std;
using p = pair<int,int>;

struct cmp {
    bool operator() (p& a, p& b){
        if (a.first==b.first) return a.second < b.second;
        else return a.first < b.first; // 인덱스가 커야됨.
    }
};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
    cin >> N;
    priority_queue<p, vector<p>, cmp> pq;

    for (int i=1; i<=N; i++){
        int num;
        cin >> num;

        // 나보다 인덱스가 작고 높이가 작은 것들을 뺀다
        while (!pq.empty() && pq.top().y < num) pq.pop();

        if (pq.empty() || pq.top().y < num) {
            cout << 0 << " ";
        } else {
            cout << pq.top().x << " ";
        }

        pq.push({i, num});
    }

   return 0;
}
