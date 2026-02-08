#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef pair<long, pair<int,int>> Edge;
vector<int> parent;

int find(int a){
    if (parent[a]==a) return a;
    else return parent[a] = find(parent[a]);
}

void unionFunc(int a, int b){
    int pA = find(a);
    int pB = find(b);

    if (a!=b) {
        // 부모끼리 합쳐준다
        parent[pB]= pA; 
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int V,E;
    cin >> V >> E;
    parent.resize(V+1);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    for (int i=1; i<=V; i++) parent[i]=i;

    for (int i=0; i<E; i++){
        int A,B,C;
        cin >> A >> B >> C;
        pq.push(make_pair(C, make_pair(A,B)));
    }

    long long ans=0;
    while (!pq.empty()){
        Edge tmp = pq.top(); pq.pop();
        long w= tmp.first; int a = tmp.second.first; int b= tmp.second.second;

        if (find(a)!=find(b)){
            unionFunc(a,b);
            ans+=w;
        }
    }

    cout << ans;
    
   return 0;
}
