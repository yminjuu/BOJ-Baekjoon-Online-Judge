#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;
long arr[10000001];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
    fill(arr, arr+10000001, 1);
   
   long long A,B;
   cin >> A >> B;

    if (A==1) A++;

    // 10000001까지의 소수를 구한다
    for (int i=2; i<=sqrt(100000001); i++){
        if (arr[i]){
            for (int j=i*i; j<=10000001; j+=i){
                    arr[j]= 0;
        }}
    }

    int ans=0;
    for (int i=2; i<=pow(10,7); i++){
        if (arr[i]){
            long long tmp=i;
            // (1) double로 먼저 안전하게 값 비교
            while ((double)tmp * i <= (double)B){
                tmp*=i;
                if (tmp>=A) ans++;
            }
        }
    }
    cout << ans;
   return 0;
}
