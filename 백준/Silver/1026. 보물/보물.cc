#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, s, S=0;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   vector<int> vecA;
   vector<int> vecB;
   
   cin >> N;

   for (int i=0; i<2; i++){
      for (int j=0; j<N; j++){
         cin >> s;
         if (i==0) vecA.push_back(s);
         else vecB.push_back(s);
      }
   }

   sort(vecA.begin(), vecA.end());
   sort(vecB.begin(), vecB.end(), greater<int>());

   for (int i=0; i<N; i++){
      S+= vecA[i] * vecB[i];
      }

   cout << S;
   return 0;
}