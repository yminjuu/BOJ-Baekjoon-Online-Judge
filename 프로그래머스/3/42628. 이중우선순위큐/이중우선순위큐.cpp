#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

// 포인트는 어떤 상황에 어떤 최소/ 최대가 삭제될지 모른다는 것 
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> mts;
    
    for (string op: operations) {
        if (op[0]=='I') {
            // 삽입
            mts.insert(stoi(op.substr(2)));
        } else if (!mts.empty()){
            if (op[2]=='1'){
                // 최댓값 삭제
                mts.erase(--mts.end());
            } else {
                // 최솟값 삭제
                mts.erase(mts.begin());
            }
        }
    }
    
    if (mts.empty()) answer = {0,0};
    else answer = { *mts.rbegin(), *mts.begin()};
    
    return answer;
}