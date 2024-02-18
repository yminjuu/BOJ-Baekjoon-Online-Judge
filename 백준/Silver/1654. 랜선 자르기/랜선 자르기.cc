#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, K, k, lft, rht, mid;
vector<long long> vec;

bool check(int n)
{
    int cnt = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        cnt += vec[i] / n;
    }
    if (cnt >= N)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> K >> N;
    for (int i = 0; i < K; i++)
    {
        cin >> k;
        vec.push_back(k);
    }
    std::sort(vec.begin(), vec.end());
    std::reverse(vec.begin(), vec.end());

    lft = 1;
    rht = vec[0];
    while (lft < rht)
    {
        mid = (lft + rht+1) / 2;
        if (check(mid))
            lft = mid;
        else
            rht = mid - 1;
    }
    cout << lft;
}