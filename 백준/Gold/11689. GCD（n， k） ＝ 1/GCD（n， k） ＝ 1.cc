#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    long n;
    cin >> n;
    long cnt=n;
    
    for (long i=2; i<=sqrt(n); i++){
        if (n%i==0){
            // i가 n의 소인수라면
            cnt= cnt - cnt/i; 

            // 다음 배수들까지 지워버렸으므로
            // 모든 소인수를 제거해야됨
            while (n%i==0)
                n /= i;
        }
    }

    // 소인수 구성이 남아있음
    if (n>1) cnt = cnt-cnt/n;
    cout << cnt;

   return 0;
}
