#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer= "";
    // 큰 숫자를 만들어가는 과정
    // 자릿수가 클수록 더 큰 숫자가 들어가야 좋음.
    
    for (int i=0; i<number.size(); i++){
        if (number[i]<number[i+1]){
            number.erase(number.begin()+i); // number이라는 string에서 i번째 인덱스 삭제 후 리사이징
            k--;
            i=-1; // i 0부터 다시 시작하도록
        }
        
        if (k<=0) break;
    }
    
    answer= number.substr(0, number.size()-k);
    
    return answer;
}