#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

char c;
int N, M, K;
int pSum[2001][2001] = {
    0,
};
char patt[3] = "BW";

int min(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;

    char patt1[2][M + 1]; // W로 시작

    // 비교 WB 셋팅
    for (int i = 1; i <= M; i++)
    {
        patt1[0][i] = patt[i % 2];       // W로 시작
        patt1[1][i] = patt[(i + 1) % 2]; // B로 시작
    }

    // pSum구하기
    for (int i = 1; i <= N; i++) // 행
    {
        for (int j = 1; j <= M; j++) // 열
        {
            cin >> c;
            pSum[i][j] = pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];
            if (c == patt1[i % 2][j])
                pSum[i][j] += 1;
        }
    }

    int mn = K * K;
    for (int i = K; i <= N; i++) // 행
    {
        for (int j = K; j <= M; j++) // 열
        {
            int k = pSum[i][j] - pSum[i - K][j] - pSum[i][j - K] + pSum[i - K][j - K];
            int diff = min(k, K * K - k);
            if (diff < mn)
                mn = diff;
        }
    }

    cout << mn;
    return 0;
}