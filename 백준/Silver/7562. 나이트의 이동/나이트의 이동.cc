#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int T, I, curX, curY, destX, destY, x, y;
int xArr[4] = {1, -1, 2, -2};
int yArr[4] = {2, -2, 1, -1};
int possible[305][305] = {
    0,
};

void knight()
{
    int dis[305][305] = {
        0,
    };
    for (int i = 2; i <= I + 1; i++)
    {
        for (int j = 2; j <= I + 1; j++)
        {
            possible[i][j] = 1;
        }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(curX, curY));
    while (!q.empty())
    {
        if (curX == destX && curY == destY)
        {
            cout << dis[destX][destY] << "\n";
            for (int i = 2; i <= I + 1; i++)
            {
                for (int j = 2; j <= I + 1; j++){
                    possible[i][j] = 0;
                }
            }
            return;
        }
        q.pop();

        for (int i = 0; i < 4; i++) // xArr
        {
            for (int j = 0; j < 2; j++) // yArr
            {
                x = curX + xArr[i]; // 1 -> -1 -> 2 -> -2
                y = curY + yArr[j + (i / 2) * 2];
                if (dis[x][y] == 0 && possible[x][y])
                {
                    q.push(make_pair(x, y));
                    dis[x][y] = dis[curX][curY] + 1;
                }
            }
        }
        curX = q.front().first;
        curY = q.front().second;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    while (T--)
    {
        cin >> I >> curX >> curY >> destX >> destY;
        curX += 2;
        curY += 2;
        destX += 2;
        destY += 2; //(2,2)부터 시작
        knight();
    }
    return 0;
}