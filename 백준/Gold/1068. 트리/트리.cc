#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
vector<vector<int>> tree;
int ans=0;
int del;

bool dfs(int node){
    if (del==node) return false;
    if (tree[node].size()==0) {
        ans++;
        return true;
    }

    int childCnt=0;
    for (int child: tree[node]){
        if (dfs(child)) childCnt++;
    }
    if (childCnt==0) {
        ans++;
    }
    return true;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
   cin >> N;
    tree.resize(N+1);

    int root;
    for (int i=0; i<=N-1; i++){
        int p;
        cin >> p;
        if (p==-1) {
            root= i;
            continue;
        }
        tree[p].push_back(i);
    } // 링크드 리스트로 트리 구현

    cin >> del; // 지울 노드

    dfs(root);

    cout << ans;
    
   return 0;
}
