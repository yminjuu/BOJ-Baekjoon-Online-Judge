#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
    cin >> N;

    int arr[1000005];

    for (int i=1; i<=N; i++){
        cin >> arr[i];
    }

    stack<int> stck;
    
    vector<int> ans(N+1);
    // 마지막 원소에서 시작해서 첫번째 원소로 간다
    
    for (int i=N; i!=0; i--){
        while (!stck.empty() && stck.top() <= arr[i]){
            stck.pop(); // 오른쪽에서 나보다 큰 수를 찾음.
        }
        
        if (stck.empty()) ans[i]= -1;
        else ans[i]= stck.top();
        
        stck.push(arr[i]);
    }

    for (int i=1; i<=N; i++){
        cout << ans[i] << " ";
    }

   return 0;
}
