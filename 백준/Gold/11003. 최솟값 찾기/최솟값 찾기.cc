#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

#define x first
#define y second

using p =pair<long,int>; 

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N,L;
    cin >> N >> L;

    deque<p> deq;

    long A; cin >> A;
    deq.push_back({A, 0}); cout << A << " ";
    
    for (int i=1; i<N; i++){
        long tmp;
        cin >> tmp;

        // (1) 인덱스 판단
        if (deq.front().y < i - L + 1) deq.pop_front(); 
        // while문이 필요 없는 이유: front에 있는 값보다 인덱스가 큰 값이 뒤에 더 있으면
        // while문이 필요한데 deq에는 순서대로 들어가므로 가능성 없음

        // (2) 값 판단
        if (tmp <= deq.back().x){
            while (!deq.empty() && tmp <= deq.back().x) deq.pop_back();
            // tmp보다 인덱스가 작고 값이 큰 값들은 어차피 tmp보다 오래 살아남지 못함.
        }
        deq.push_back({tmp, i}); // 후보를 일단 넣어야 됨.
        cout << deq.front().x << " ";
    }

   return 0;
}
