#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int arr[3][2];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   for (int i=0; i<3; i++){
       for (int j=0; j<2; j++){
           cin >> arr[i][j];
       }
   }

    // 오른쪽 아래로 곱해서 더하고 , 왼쪽 아래로 곱해서 뺀다.
    long ccw=0;
    for (int i=0; i<3; i++){
        ccw+= arr[i][0] * arr[(i+1)%3][1];
        ccw-= arr[(i+1)%3][0] * arr[i][1];
    }

    if (ccw>0) cout << 1;
    else if (ccw<0) cout << -1;
    else cout << 0;

   return 0;
}
