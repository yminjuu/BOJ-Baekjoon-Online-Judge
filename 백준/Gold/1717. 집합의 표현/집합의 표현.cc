#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
vector<int> parent;

int find(int a){
    if (parent[a]==a) return a;
    else return parent[a] = find(parent[a]);
}

void unionFunc(int a, int b){
    int parentA = find(a);
    int parentB = find(b);

    // 부모 노드 수준에서 union이 발생해야 한다.
    if (parentA < parentB) parent[parent[b]] = parentA; // 작은 값이 대표값
    else parent[parent[a]] = parentB;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;
    parent.resize(N+1);
    for (int i=0; i<=N; i++){
        parent[i]= i;
    }

    int i, a, b;
    while (M--){
        cin >> i >> a >> b;
        if (i==0) unionFunc(a,b);
        else {
            if (find(a)==find(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

   return 0;
}
