#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

#define MOD 1000000007
vector<long> tree;

void changeVal(int idx, long val){
    tree[idx]= val;
    
    while (idx>0){
        idx/=2;
        tree[idx] = tree[idx*2] * tree[idx*2+1] % MOD;
        // 곱셈이므로 기존값을 재활용하지 않고 새롭게 곱해줌
    }
    return;
}

long getMult(int s, int e){
    long res=1;
    while (s<=e){
        if (s%2==1) res = res * tree[s] % MOD;
        if (e%2==0) res = res * tree[e] % MOD;
        s = (s+1)/2;
        e = (e-1)/2;
    }
    return res;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M, K; 
   cin >> N >> M >> K;

    long lth = N;
    long treeHeight = 0;
    while (lth>0){
        lth/=2;
        treeHeight++;
    }

    long treeSize = pow(2, treeHeight+1);
    long leafLeftNodeIdx = pow(2, treeHeight);
    tree.resize(treeSize+1, 1); // 곱이기에 1로 초기화

    for (int i=0; i<N; i++){
        cin >> tree[leafLeftNodeIdx+i];
    }

    // 트리 구성하기
    for (int i=leafLeftNodeIdx-1; i!=0; i--){
        tree[i] = tree[i*2] * tree[i*2+1] % MOD;
    }

    for (int i=0; i<M+K; i++){
        long a,b,c;
        cin >> a >> b >> c;
        if (a==1) changeVal(b+leafLeftNodeIdx-1, c);
        else cout << getMult(leafLeftNodeIdx + b - 1, leafLeftNodeIdx + c-1) << "\n";
    }

   return 0;
}
