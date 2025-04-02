#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; 
typedef long long ll;
ll n, k, ans, temp1, temp;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> k;
	vector<pair<ll,ll> > v(n);
	vector<ll> vv(k); 
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second; 
	}
	for(int i = 0; i < k; i++) cin >> vv[i]; 
	sort(v.begin(), v.end()); 
	sort(vv.begin(), vv.end());
	priority_queue<ll> pq;
	
	int dia=0;
    for (int bag=0; bag<k; bag++){
        while (dia<n && v[dia].first<= vv[bag]) pq.push(v[dia++].second);
        if (pq.size()) {ans+=pq.top(); pq.pop();}
    }
	cout << ans << "\n"; 
	return 0;
}     