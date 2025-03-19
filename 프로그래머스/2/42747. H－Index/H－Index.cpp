#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a>=b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    // 6 1 0 0
    
    // 누적 인용수를 구한다
    // 1 2 3 4 
    
    sort(citations.begin(), citations.end(), desc);
    for (int i=1; i<=citations.size(); i++){
        int tmp = citations[i-1]<=i ? citations[i-1] : i;
        answer = max(tmp, answer);
    }
    
    return answer;
}