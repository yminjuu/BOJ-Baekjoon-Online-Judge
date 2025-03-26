#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    stack<int> stck;
    for (int i=progresses.size()-1; i>=0; i--){
        int days = ceil((100 - progresses[i]) / (double) speeds[i]);
        stck.push(days);
    }
    
    while (!stck.empty()){
        int basis = stck.top(); stck.pop();
        int cnt = 1;
        while (!stck.empty() && stck.top() <= basis){
            stck.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}

// 100에서 뺀 값을 speed로 나눈다
// 7 3 9

// 5 10 1 1 20 1
// 가장 앞에 있는 값을 저장해두고 