#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int P;
    cin >> P;

    while (P--) {
        int T;
        cin >> T;
        cout << T << " ";

        vector<int> v;
        int ans = 0;

        for (int j = 0; j < 20; j++) {
            int n;
            cin >> n;

            // n보다 큰 첫 번째 원소의 위치를 찾음
            auto it = upper_bound(v.begin(), v.end(), n);
            
            // 만약 n보다 큰 원소들이 있다면
            if (it != v.end()) {
                // n 뒤에 서게 될 학생들의 수만큼 ans 증가
                ans += (v.end() - it);
                v.insert(it, n);
            } else {
                // n이 현재 줄에서 가장 크다면 맨 뒤에 추가
                v.push_back(n);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}