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

    int arr[101][101];
    fill(&arr[0][0], &arr[100][100]+1, 0);

    int paper;
    cin >> paper;

    for (int i=0; i<paper; i++){
        int r, c;
        cin >> r >> c;

        for (int row=r; row<r+10; row++){
            for (int col=c; col<c+10; col++){
                arr[row][col]= 1;
            }
        }
    }

    int ans = 0;
    
    for (int row=0; row<100; row++){
            for (int col=0; col<100; col++){
                if (arr[row][col]==1) ans++;
            }
    }

    cout << ans;

   return 0;
}
