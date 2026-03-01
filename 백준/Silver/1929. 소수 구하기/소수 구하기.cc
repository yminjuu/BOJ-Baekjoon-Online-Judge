#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> M >> N;

    int visited[N+1];
    fill(&visited[0], &visited[N]+1, 0);
    visited[1] = 1; // 예외처리

    // N 제곱근까지만
    for (int i=2; i<= sqrt(N); i++){
        if (visited[i]) continue; // 이미 소수가 아님 => 지워졌을 것
        for (int j=i+i ; j<=N; j+=i) {
            if (!visited[j]) visited[j]= 1;
        }
    }

    for (int i=M; i<=N; i++){
        if (!visited[i]) cout << i << "\n";
    }

   return 0;
}
