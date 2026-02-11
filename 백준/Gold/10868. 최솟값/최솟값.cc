#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <climits>

using namespace std;
vector<long> tree;

long findMin(long s, long e) {
    vector<long> vec;
    while (s<=e){
        if (s%2==1) vec.push_back(tree[s]);
        if (e%2==0) vec.push_back(tree[e]);
        s = (s+1)/2;
        e = (e-1)/2;
    }
    long min_val = *min_element(vec.begin(), vec.end());
    return min_val;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;

    long treeHeight = 0;
    long nodes = N;
    while (nodes!=0){
        nodes/=2;
        treeHeight++;
    }

    long treeSize = pow(2, (treeHeight+1));
    long leftNodeStartIdx = pow(2, treeHeight); // 1 시작 기준 인덱스
    tree.resize(treeSize+1, LLONG_MAX);

    // 입력 받기
    for (int i=0; i<N; i++){
        cin >> tree[leftNodeStartIdx+i];
    }

    // 트리 구성하기
    for (int i=leftNodeStartIdx-1; i>0; i--){
        tree[i]= min(tree[i*2], tree[i*2+1]); // 최솟값 넣기
    }

    while (M--){
        int s, e;
        cin >> s >> e;
        cout << findMin(leftNodeStartIdx + s -1, leftNodeStartIdx + e - 1) << "\n";
    }

   return 0;
}
