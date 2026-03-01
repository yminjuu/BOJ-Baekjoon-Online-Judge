#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define x first
#define y second
using p = pair<int,int>;

struct cmp {
    bool operator() (p &a, p &b) const {
        // pq는 반대
        if (a.x==b.x) return a.y > b.y; // 들어간 순서
        else return a.x < b.x; // 중요도 
    }
};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int T;
    cin >> T;

    while (T--){
        int N,M;
        cin >> N >> M;
        
        queue<p> q; // 순서가 중요하므로 q 사용
        priority_queue<p, vector<p>, cmp> pq; // 중요도를 참고하기 위해 pq 사용
        
        for (int i=0; i<N; i++){
            int priority;
            cin >> priority;
            q.push({priority, i});
            pq.push({priority, i});
        }

        int cnt=0;
        while (!q.empty()){
            auto [priority, idx] = q.front();
            
            if (pq.top().x > priority) {
                q.push({priority,idx}); // 뒤로 보낸다
                q.pop();
            } else {
                // 같을 때
                pq.pop();
                q.pop();
                cnt++;

                // 인쇄
                if (idx==M) {
                    cout << cnt << "\n";
                    break;
                }
            }
        } 
    }

   return 0;
}
