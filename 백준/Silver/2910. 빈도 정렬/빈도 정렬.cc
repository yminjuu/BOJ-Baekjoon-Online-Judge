#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
map<int, int> _map; 
map <int, int> order; 

int N,C, tmp;

bool comp(pair<int,int> a, pair<int,int> b){
   if (a.second!=b.second) return a.second>b.second;
   else {
        return order[a.first] < order[b.first];
   }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> N >> C;

   for (int i=0; i<N; i++) {
    cin >> tmp;
    _map[tmp]++; 
    if (order[tmp]==0) order[tmp]=order.size(); 
   }

   vector<pair<int,int> > vec(_map.begin(), _map.end());

   sort(vec.begin(), vec.end(), comp);

   for (auto itr : vec) {
    for (int i=0; i<itr.second; i++){
        cout << itr.first << " ";
    }
   }

   return 0;
}