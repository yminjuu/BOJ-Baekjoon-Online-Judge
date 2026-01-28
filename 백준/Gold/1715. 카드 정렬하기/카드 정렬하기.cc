#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    int ans =0;
    while (pq.size()>1){
        int mn1= pq.top(); pq.pop();
        int mn2= pq.top(); pq.pop();
        ans+=mn1+mn2;
        pq.push(mn1+mn2);
    }

    cout << ans;

   return 0;
}
