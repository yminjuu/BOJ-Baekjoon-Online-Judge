#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
vector<int> vec;
vector<int> parent;
vector<vector<int>> party;

int find(int x){
    if (parent[x]==x) return x;
    else return parent[x] = find(parent[x]);
}

void unionFunc(int a, int b){
    a = find(a);
    b = find(b);

    if (a!=b) parent[b]= a;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;
    parent.resize(N+1);
    party.resize(M+1);

    for (int i=1; i<=N; i++){
        parent[i]= i;
    }

    int truth;
    cin >> truth;
    while (truth--){
        int person;
        cin >> person;
        vec.push_back(person);
    }

    // 같은 파티에 있는 사람끼리는 한 집합에 묶는다
    int cnt, a, parentBase;
    for (int i=0; i<M; i++){
        cin >> cnt;
        if (cnt==0) continue;

        cin >> a;
        parentBase = a; cnt--; party[i].push_back(a);
        while (cnt--){
            cin >> a;
            unionFunc(parentBase, a);
            party[i].push_back(a);
        }        
    }

    for (int i=0; i<vec.size(); i++){
        find(vec[i]);
    }

    int ans = M;
    // 진실을 아는 사람들이 바라보고 있는 대표노드와 파티의 한 노드를 각각 비교
    for (int i=0; i<M; i++){
        for (int j=0; j<vec.size(); j++){
            if (find(vec[j])==find(party[i][0])) {
                ans--;
                break;
            }
        }
    }
    
    cout << ans;

   return 0;
}
