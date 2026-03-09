#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
    cin >> N;

    if (N%2==0) cout << "CY";
    else cout << "SK";

   return 0;
}
