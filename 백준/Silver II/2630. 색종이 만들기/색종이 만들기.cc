#include <iostream>
#include <queue>
#include <string>
using namespace std;
int N;
int arr[129][129];
int color[2] = {0,};

int Cpap(int x, int y, int n)
{
    if (n == 1)
        return arr[x][y];
    int tmp[2][2];
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            tmp[i][j] = Cpap(x + (n / 2) * i, y + (n / 2) * j, n / 2);
        }
    }

    if (tmp[0][0] == tmp[0][1] && tmp[0][0] == tmp[1][0] && tmp[0][0] == tmp[1][1]){
        if (n == N)
            return (++color[tmp[0][0]]);
        else
            return tmp[0][0];}
    else{
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                if (tmp[i][j] != -1)
                    color[tmp[i][j]]++;
            }
        }
        return -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }
    }

    Cpap(0, 0, N);

    cout << color[0] << "\n"<< color[1];

    return 0;
}