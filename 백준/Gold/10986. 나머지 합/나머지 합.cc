#include <iostream>
#include <algorithm>
using namespace std;

long long N, M, k, ans = 0;
long long cnt[1001] = {
    0,
};
long long sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> k;
        sum += k;
        cnt[sum % M] += 1;
    }

    for (int i = 0; i <= 1000; i++)
    {
        ans += (cnt[i] * (cnt[i] - 1) / 2);
    }

    cout << ans + cnt[0];
    return 0;
}