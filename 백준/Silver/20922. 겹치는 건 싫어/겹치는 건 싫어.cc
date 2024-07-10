#include <iostream>
#include <limits.h>
#include <algorithm>
#include <queue>

using namespace std; 

int N,K,a,mx=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;

    queue<int> q; // 현재 범위에 들어와있는 수열을 담는 큐
    int number[200001]= {0, }; 

    for (int i=0; i<N; i++){
        cin >> a; q.push(a);
        number[a]++;
        if (number[a]<=K) {
            if (q.size() > mx) mx= q.size(); //갱신
        } else {
            while (q.size()){
                int k = q.front(); q.pop();
                number[k]--;
                if (k==a) break;
            }
        }
    }
    cout << mx ;
    return 0;
}