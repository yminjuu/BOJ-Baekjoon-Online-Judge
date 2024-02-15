#include <iostream>
using namespace std;
long long N, K;
long long P = 1000000007;

// k의 거듭제곱을 p로 나눈 나머지를 구하는 함수
long long mult(long long k, long long pw)
{ // k의 pw 거듭제곱을 p로 나눈 나머지 리턴
    if (pw == 0)
        return 1;
    if (pw == 1)
        return k % P;
    long long tmp = mult(k, pw / 2);
    if (pw % 2 == 0)
    {
        return tmp * tmp % P;
    }
    else
    {
        return (tmp * tmp % P) * k % P;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    long long A = 1;
    for (long long i = N; i != 0; i--)
    {
        A *= i;
        A %= P;
    }

    long long B = 1;
    for (long long i = K; i != 0; i--)
    {
        B *= i;
        B %= P;
    }

    long long C = 1;
    for (long long i = (N - K); i != 0; i--)
    {
        C *= i;
        C %= P;
    }

    cout << ((A % P) * mult(B * C % P, P - 2)) % P;

    return 0;
}