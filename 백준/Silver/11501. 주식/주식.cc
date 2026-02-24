#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
using ll= long long;

ll test(){
    ll n;
    ll ans=0; 
    
    cin >> n;
    ll price[n+1];

    for (long i =0; i<n; i++){
        cin >> price[i];
    }

    queue<ll> q;
    ll maxPrice= price[n-1]; // 최대 주가
    for (long i=n-2; i>=0; i--){
       if (maxPrice < price[i]){
           // maxPrice에 지금까지 q에 모은 주식을 판다
           while (!q.empty()){
               int prevPrice = q.front(); q.pop();
               ans+= (maxPrice-prevPrice);
           }
           maxPrice = price[i]; // maxPrice 갱신
       } else {
           // 넣는다
           q.push(price[i]);
       }
    }

    // 남은 주식을 마지막 가격에 판다
    while (!q.empty()){
        int prevPrice = q.front(); q.pop();
        ans += (maxPrice-prevPrice);
    }

    return ans;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while (T--){
        cout << test() << "\n";
    }

   return 0;
}
