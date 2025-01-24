#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;

int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   while (cin >> n) {
      int cnt=1; long long int num=1;
      while (true){
         if (num%n==0) {
            cout << cnt << endl;
            break;
         }
         else {
            num = (num*10)+1;
            cnt++;
            num%= n;
         }
      }
   }

   return 0;
}