#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int N, sz, curr, ans=0;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   priority_queue<int, vector<int>, greater<int> > pq;

   cin >> N;
   for (int i=0; i<N; i++) {
    cin >> sz;
    pq.push(sz);
   }

   while (pq.size() >1 ){
        curr = pq.top(); pq.pop();
        curr += pq.top(); pq.pop();
        ans += curr;
        pq.push(curr);
   }

   cout << ans;
   
   return 0;
}