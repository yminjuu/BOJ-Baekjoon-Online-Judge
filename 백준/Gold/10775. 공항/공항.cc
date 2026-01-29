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
   
   int G, P;
   cin >> G >> P;
   vector<int> maxGate(P+1);
   vector<bool> docked(G+1, false);
   vector<int> lastGateForMaxGate(G+1);

   for (int i=1; i<=P; i++){
    cin >> maxGate[i];
   }

   for (int i=1; i<=G; i++){
    lastGateForMaxGate[i]= i;
   }

   int ans =0 ;
   for (int i=1; i<=P; i++){
        int j=lastGateForMaxGate[maxGate[i]];
        for (; j!=0; j--){
            if (!docked[j]){
                docked[j]= true;
                lastGateForMaxGate[maxGate[i]]--;
                ans++;
                break;
            }
        }
        if (j==0){
            // 도킹 불가능
            cout << ans;
            return 0; // 종료
        }

   }

   cout << ans;

   return 0;
}