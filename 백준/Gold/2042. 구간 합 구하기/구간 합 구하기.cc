#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <numeric>

using namespace std;
vector<long long> tree;

// 구간합 구하기
long getSum(long s, long e){
    long long sum=0;
    while (s<=e){
        if (s%2==1) sum+=tree[s];
        if (e%2==0) sum+=tree[e]; 
        s= (s+1)/2;
        e= (e-1)/2;
    }
    return sum;
};

// 데이터 변경
void changeVal(int idx, long val){
    long diff = val - tree[idx];
    
    while (idx>0) {
        tree[idx]+=diff;
        idx/=2;
    }

};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M, K; 
   cin >> N >> M >> K;
    int treeHeight=0; // 루트 높이가 0일 때에 트리 높이
    int length = N;

    while (length!=0){
        length/=2; 
        treeHeight++;
    }

    long treeSize = long(pow(2, treeHeight+1));
    long leftLeafStartIdx = long(pow(2, treeHeight));
    tree.resize(treeSize+1);
    
    // 트리 입력 받기
    for (int i=0; i<N; i++){
        long a;
        cin >> a;
        tree[i+leftLeafStartIdx] = a;
    }

    // 초기 트리 구성하기
    for (int i= leftLeafStartIdx-1; i>0; i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }

    for (int i=0; i<M+K; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        if (a==1) {
            changeVal(leftLeafStartIdx+b-1, c);
        }
        else {
            cout << getSum(leftLeafStartIdx+ b-1,leftLeafStartIdx+ c-1) << "\n";
        }
    }

   return 0;
}
