#include <iostream>
using namespace std;
long long A, B, C;

long long mult(long long b)
{
    if (b == 0)
        return 1; // A의 0승 : 1
    if (b == 1)
        return A % C;
    long long tmp = mult(b / 2);
    if (b % 2 == 0)
    { // 짝수면
        return (tmp * tmp) % C;
    }
    else
    {
        return ((tmp * tmp % C) * A % C);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B >> C;

    cout << mult(B);

    return 0;
}