#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int cost, cnt=0;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   int remains[6]={ 500, 100, 50, 10, 5, 1};
   
   cin >> cost;
   cost= 1000- cost;
   for (int i=0; i<6; i++){
        int tmp= cost / remains[i];
        cost -= remains[i]*tmp;
        cnt+= tmp;
   }

    cout << cnt;
   
   return 0;
}