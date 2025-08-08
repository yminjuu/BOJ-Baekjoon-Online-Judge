#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
int N, P, L, M;
string str;

struct Problem {
   int diff; // 난이도
   int id; // 문제 번호
};

struct Cmp {
   bool operator()(const Problem& a, const Problem& b) const {
      if (a.diff!= b.diff) return a.diff < b.diff;
      else return a.id < b.id;
   }
};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   set<Problem, Cmp> problems; 
   unordered_map<int, int> pos; 

   cin >> N; // 문제 개수

   for (int i=0; i<N; i++){
      // 문제를 넣고
      cin >> P >> L;
      problems.insert({L,P});
      pos[P]= L;
   }
   
   cin >> M;

   for (int i=0; i<M; i++){
      cin >> str;
      if (str=="add"){
         cin >> P >> L;
         problems.insert({L,P});
         pos[P]= L;
      } else if (str=="solved"){
         cin >> P;
         problems.erase({pos[P],P});

      } else if (str=="recommend") {
         cin >> L;
         if (L==1) {
            cout << problems.rbegin()->id << "\n";
         } else {
            cout << problems.begin()->id << "\n";
         }
      }
   }

   return 0;
}