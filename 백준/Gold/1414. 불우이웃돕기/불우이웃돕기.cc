#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
vector<int> parent;
long totalLength=0;

// struct 정의 방식
typedef struct Edge {
    int s, e, w;
    bool operator > (const Edge& temp) const {
        return w > temp.w;
    }
} Edge;

int find(int a){
    if (parent[a]==a) return a;
    else return parent[a]= find(parent[a]);
}

void unionFunc(int a, int b){
    int parentA= find(a);
    int parentB= find(b);

    if (parentA!=parentB){
        parent[parentB]= parentA;
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    int N;
    cin >> N;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    parent.resize(N+1);

    for (int i=1; i<=N; i++){
        parent[i]= i;
    }

    for (int i=1; i<=N; i++){
            string str;
            cin >> str;
            for (int k=0; k<str.length(); k++){
                char c= str[k]; int weight;
                if (c=='0') continue;
                if (c>='a' && c<='z') weight = c-'a'+1;
                if (c>='A' && c<='Z') weight = c-'A'+27;
                
                if (i!=k+1) pq.push(Edge{i,k+1,weight});
                totalLength+=weight;
            }
    }

    int connect= 0; 
    while (!pq.empty() && connect<N){
        Edge edge = pq.top(); pq.pop();
        
        if (find(edge.s)!=find(edge.e)){
            unionFunc(edge.s, edge.e);
            totalLength-=edge.w;
            connect++;
        }
    }

    if (connect!=N-1) {
        cout << -1;
    } else {
        cout << totalLength;
    }

   return 0;
}
