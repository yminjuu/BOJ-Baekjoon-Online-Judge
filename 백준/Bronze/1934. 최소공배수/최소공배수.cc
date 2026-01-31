#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int GCD(int a, int b){
    int r = a%b;
    if (r==0) return b; 
    
    a = b; 
    b = r;
    return GCD(a,b); 
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    int T, a,b;
    cin >> T;
    
    while (T--){
        cin >> a >> b;
        if (a<b){
            int tmp= b;
            b= a;
            a= tmp;
        }
        int gcd= GCD(a,b);
        cout << gcd*(a/gcd)*(b/gcd) << "\n";
    }
    return 0;
}
