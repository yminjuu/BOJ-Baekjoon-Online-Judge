#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

// 최대 공약수 구하기
long gcd(int a,int b){
    if (b==0) return a;
    else return gcd(b, a%b);
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    int T;
    cin >> T;

    while (T--){
        long a,b;
        cin >> a >> b;
        long gcdNum = gcd(a,b);
        cout << a/gcdNum * b/gcdNum * gcdNum  << "\n";
    }
    
   return 0;
}
