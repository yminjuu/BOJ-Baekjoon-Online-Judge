#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
using ll = long long;

vector<long long> trees;
int N,M;

bool isPossible(ll h){
    ll sum=0;
    for (int i=0; i<trees.size();i++){
        if (trees[i]<=h) continue; // 음수 예외!!!!
        sum+= (trees[i] - h); 
    }
    if (sum>=M) return true;
    else return false;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N >> M;

    for (int i=0; i<N; i++){
        long long tmp;
        cin >> tmp;
        trees.push_back(tmp);
    }

    // 파라메트릭 서치 적용
    ll s= 1;
    ll e= 2000000000;

    ll ans = 0;
    while (s<=e){
        ll mid = (s+e)/2;

        bool res = isPossible(mid);
        if (res) {
            ans= mid;
            s= mid+1;
        } else {
            e= mid-1;
        }
    }

    cout << ans;

   return 0;
}
