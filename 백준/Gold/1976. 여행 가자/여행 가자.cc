#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
vector<int> parent;
vector<vector<int>> city;

int find(int a){
    if (parent[a]==a) return a;
    else return parent[a]= find(parent[a]);
}

void unionFunc(int a, int b){
    // 대푯값
    a= find(a);
    b= find(b);

    if (a!=b){
        parent[b] = a; // 대푯값끼리 연결
    }
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;

    parent.resize(N+1);
    city.resize(N+1);

    for (int i=1; i<=N; i++){
        parent[i]= i;
        city[i].resize(N+1);
        fill(city[i].begin(), city[i].end(), 0);
    }

    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            int tmp;
            cin >> tmp;
            city[i][j]= tmp;
        }
    }

    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (i!=j && city[i][j]){
                // 연결되어 있다면
                unionFunc(i, j);
            }
        }
    }

    int a; cin >> a; int pA = find(a);
    for (int i=2; i<=M; i++){
        int b;
        cin >> b;
        if (find(b)!=pA) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

   return 0;
}
