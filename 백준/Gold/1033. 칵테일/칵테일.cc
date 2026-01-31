#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans[10];
vector <tuple<int, int, int>> adj[10];

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 그래프 및 최소공배수 세팅
	int n;
	ll tot_lcm = 1;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll a, b, p, q;
		cin >> a >> b >> p >> q;
		adj[a].push_back({ b, p, q });
		adj[b].push_back({ a, q, p });
		tot_lcm *= lcm(p, q);
	}
	
	// BFS를 위한 초기 설정
	ans[0] = tot_lcm;
	queue<int> q;
	q.push(0);

	// BFS
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto nb : adj[cur]) {
			if (ans[get<0>(nb)]) continue;
			ans[get<0>(nb)] = (ans[cur] * get<2>(nb)) / get<1>(nb);
			q.push(get<0>(nb));
		}
	}

	// 최대공약수 계산 및 출력
	ll ans_gcd = ans[0];
	for (int i = 1; i < n; i++) ans_gcd = gcd(ans_gcd, ans[i]);
	for (int i = 0; i < n; i++) cout << ans[i] / ans_gcd << ' ';

	return 0;
}