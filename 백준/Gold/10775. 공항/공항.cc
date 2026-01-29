#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
vector<int> parent;

int find(int gate){
    if (parent[gate]==gate) return gate;
    return parent[gate]= find(parent[gate]); 
}

// a > b
void union_sets(int a, int b){
    a= find(a); 
    b= find(b); 
        parent[a]= parent[b];
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int G, P;
   cin >> G >> P;
   vector<bool> docked(G+1, false);
   parent.resize(G+1);

   for (int i=1; i<=G; i++){
    parent[i]= i; 
   }

   int tmp, ans =0 ;
   for (int i=1; i<=P; i++){
    cin >> tmp;

    int emptyGate= find(tmp); 

    if (emptyGate==0){
        break;
    }

    ans++;
    union_sets(emptyGate, emptyGate-1);
   }

   cout << ans;

   return 0;
}