#include <iostream>
using namespace std;

long long A, B;
int ans = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> A >> B;
    
    while (B > A) {
        if (B % 10 == 1) {
            B /= 10;
        } else if (B % 2 == 0) {
            B /= 2;
        } else {
            // 만들 수 없는 경우
            cout << -1;
            return 0;
        }
        ans++;
    }

    if (B == A) {
        cout << ans;
    } else {
        cout << -1;
    }

    return 0;
}
