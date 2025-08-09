#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int T, M, tmp;
multiset<int> leftSet, rightSet;

void rebalance(){
   if (leftSet.size() > rightSet.size()+1){
      auto it = prev(leftSet.end()); 
      rightSet.insert(*it);
      leftSet.erase(it);
   } 
   else if (rightSet.size() > leftSet.size()) {
       auto it = rightSet.begin();
        leftSet.insert(*it);
        rightSet.erase(it);
   }
}

void insertNum(int num){
   if (leftSet.empty() || num <= *leftSet.rbegin())
      leftSet.insert(num); // 
   else 
      rightSet.insert(num);
   rebalance();
}

int getMedian(){
   return *leftSet.rbegin();
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> T;
   
   while (T--){
      leftSet.clear(); rightSet.clear();
      cin >> M;
      if (M%2==0) cout << M/2 << "\n";
      else cout << M/2+1 << "\n"; 

      for (int i=0; i<M; i++){
         cin >> tmp;
         insertNum(tmp);

         if (i%2==0){
            cout << getMedian() << " ";
         }
      }
      cout << "\n";
   }

   return 0;
}