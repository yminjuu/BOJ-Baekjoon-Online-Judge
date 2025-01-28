#include <string>
#include <vector>

using namespace std;
int realAns, length, sum=0;

void addSub(int index, vector<int> numbers, int target){
    // 더하기
    sum+=numbers[index];
    if (index!=length) addSub(index+1, numbers, target);
    else {
        if (target==sum) realAns++;
    }
    
    // 빼기
    sum-=(numbers[index]*2);
    if (index!=length) addSub(index+1, numbers, target);
    else {
        if (target==sum) realAns++;
    }
    
    // 원상 복구
    sum+=numbers[index];
    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    length = numbers.size()-1;
    
    addSub(0, numbers, target);
    
    return realAns;
}