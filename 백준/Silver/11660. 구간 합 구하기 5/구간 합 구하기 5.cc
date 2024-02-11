#include <iostream>
#include <algorithm>
using namespace std;

int N, M, x, y, xx, yy;
int arr[1025][1025];
int pSum[1025][1025] = {
    0,
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            pSum[i][j] = arr[i][j] + pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];
        }
    }

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> xx >> yy;
        cout << (pSum[xx][yy] - pSum[x - 1][yy] - pSum[xx][y - 1] + pSum[x - 1][y - 1]) << "\n";
    }

    return 0;
}