#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int N,M;
int ans;
vector<int> parent; 

int findRoot(int x){
    if (parent[x]==x) return x;
    return parent[x] = findRoot(parent[x]);
}

void merge(int a, int b){
    int newA= findRoot(a); 
    int newB= findRoot(b); 

    if (newA!=newB){
        parent[a]= newB;
    }
}

void Book(){
    ans =0;
    cin >> N >> M;
    parent.resize(N+2, 0);

    for (int i=1; i<=N+1; i++){
        parent[i]=i;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> ranges;
    for (int i=1; i<=M; i++){
        int a,b;
        cin >> a >> b;
        ranges.push(make_pair(b,a));  
    }

    while (!ranges.empty()){
        int b= ranges.top().first;
        int a = ranges.top().second;

        int candidate = findRoot(a);
        if (candidate!=0 && candidate<=b){
            ans++;
            merge(candidate, candidate+1);
        }
        ranges.pop();
    }

    cout << ans << endl;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int T;
   cin >> T;
   while (T--){
    Book();
   }

   return 0;
}
