#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer= "";
    
    int N= number.length();
    stack<int> stck;
    
    int i=0;
    for (; i<N; i++){
        int n = number[i]-'0';
        
        // 지금 들어가는 수보다 작은 게 있으면 다 뺀다
        while ((!stck.empty() && stck.top() < n) && k!=0){
            stck.pop();
            k--;
        }
        stck.push(n);
    }
    
    // 내림차순으로 완성된 상황
    while (!stck.empty()){
        int n = stck.top(); stck.pop();
        answer = to_string(n) + answer;
    }
    
    // 자르기
    answer = answer.substr(0, N-k);
    
    return answer;
}