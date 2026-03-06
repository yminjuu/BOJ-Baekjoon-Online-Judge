#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int N= numbers.size();
    
    int bigNum[N+2];
    
    bigNum[N-1]= -1;
    
    for (int i=N-2; i>=0; i--){
        int currNum = numbers[i];
        int nextIdx = i+1; // 다음 위치의 수
        
        while (numbers[nextIdx] <= currNum){
            // 찾을 때까지 타고 간다
            nextIdx= bigNum[nextIdx];
            
            if (nextIdx==-1) break;
        }
        
        bigNum[i]= nextIdx;
    }
    
    for (int i=0; i<N; i++){
        if (bigNum[i]!=-1) answer.push_back(numbers[bigNum[i]]);
        else answer.push_back(-1);
    }
    
    return answer;
}