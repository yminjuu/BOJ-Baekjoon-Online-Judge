#include <iostream>
#include <queue>
#include <string>
using namespace std;
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int dist[N - 1];
    int price[N];

    for (int i = 0; i < N - 1; i++) cin >> dist[i];
    for (int i = 0; i < N; i++) cin >> price[i];

    long long sum = 0;
    long long disSum = 0;
    long long currPrice = 1000000001;
    for (int i = 0; i < N - 1; i++)
    {
        if (currPrice <= price[i])
        {
            disSum += dist[i];
        }
        else
        {
            sum += currPrice * disSum;
            currPrice = price[i];
            disSum = 0;
            disSum += dist[i];
        }
    }
    sum += currPrice * disSum;
    cout << sum;

    return 0;
}