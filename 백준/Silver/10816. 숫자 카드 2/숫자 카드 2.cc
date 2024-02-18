#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, k, mid;
map<int, int> mp;
vector<int> vec; // 키값 벡터

int binary(int low, int high, int k)
{
    if (low > high)
        return 0;
    mid = (low + high) / 2;
    if (vec[mid] == k)
        return mp[k];
    if (k < vec[mid])
        return binary(low, mid - 1, k);
    if (vec[mid] < k)
        return binary(mid + 1, high, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        if (mp.find(k) == mp.end())
        {                               // 존재x
            mp.insert(make_pair(k, 1)); // key값 기준 오름차순 정렬
        }
        else
        {
            mp[k]++; // value 갱신
        }
    }

    for (auto it = mp.cbegin(); it != mp.cend(); ++it)
    {
        vec.push_back((*it).first);
    }

    for (auto it = mp.begin(); it != mp.cend(); ++it)
    {
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> k;
        cout << binary(0, mp.size() - 1, k) << " ";
    }
}