#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>
#include <set>
#include <iterator>

using namespace std;
int N, C;

using ll =long long;
using p= pair<ll,ll>;

vector<ll> house;
set<ll> wifis;

// 1 2 4 8 9
// 이분 탐색을 통해 해당 구간에서 가장 먼 공유기 한 개를 찾는다.
bool decide(int minDist){
    int cnt=1; // 시작점엔 무조건 둔다.
    ll last= house[0];
    for (int i=1; i<N; i++){
        // 잘못된 점: j를 하나 더 두고 모든 구간을 탐색하려고 함
        if (house[i]-last >= minDist) {
            cnt++;
            last= house[i];
        }
    }

    if (cnt>=C) return true;
    else return false;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    cin >> N >> C;

    for (int i=0; i<N; i++){
        ll tmp;
        cin >> tmp;
        house.push_back(tmp);
    }
    sort(house.begin(), house.end());

    ll s = 1;
    ll e = house[N-1]-house[0];
    ll ans = LLONG_MIN; // 정답으로 판단된 최대 거리

    while (s<=e){
        ll mid = (s+e)/2;

        if (decide(mid)){
            ans = max(mid, ans);
            s= mid+1; // 더 늘려본다.
        } else {
            e= mid-1; // 안되므로 줄인다.
        }
    }

    cout << ans;
    
   return 0;
}
