#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;
int ans[100005];

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<int> stck;
    int N= prices.size();
    
    ans[N-1]= 0; stck.push(prices[N-1]);
    
    for (int i=N-2; i>=0; i--){
        if (stck.top() >= prices[i]){ // 내가 더 작음
            while (!stck.empty() && stck.top() > prices[i]){
                stck.pop();
            }
            stck.push(prices[i]);
            ans[i]= (N-1) - i; // 내려가지 않음
        } else {
            // 내가 더 큼 -> 언젠가 내려감.
            int nextIdx= i+1;
            while (prices[nextIdx] >= prices[i] && nextIdx<N){
                nextIdx= nextIdx + ans[nextIdx];
            }
            ans[i]= nextIdx- i;
        }
    }
    
    for (int i=0; i<N; i++){
        answer.push_back(ans[i]);
    }
    
    return answer;
}