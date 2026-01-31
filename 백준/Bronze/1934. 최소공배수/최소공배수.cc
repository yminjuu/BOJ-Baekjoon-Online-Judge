#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int GCD(int a, int b){
    int A = a; int B= b;
    while (true){ 
        int r = A%B;
        if (r==0) break; 
        A = B; 
        B = r;
    }
    return B;
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
