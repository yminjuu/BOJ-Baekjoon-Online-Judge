#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int parent[1000005];

// 최상위 원소를 찾아 반환 / parent 갱신
int find(int n){
    if (parent[n]==n) return n;
    else return parent[n]= find(parent[n]);
}

void unionFunc(int a, int b){
    int pA= find(a);
    int pB= find(b);

    if (pA!=pB) {
        // 부모 집합끼리 합친다
        parent[pB]= pA; 
    }
}

// 집합 0~n 총 n+1개
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;

    // parent 배열 초기화
    for (int i=0;  i<=N; i++){
        parent[i]= i;
    }

    while (M--){
        int method, a, b;
        cin >> method >> a >> b;
        if (method==0){
            // 집합 합치기
            unionFunc(a,b);
        } else if (method==1){
            // 같은 집합에 포함되어 있는지 확인
            if (find(a)==find(b)){
                cout << "YES\n";
            } else cout << "NO\n";
        }
    }

   return 0;
}
