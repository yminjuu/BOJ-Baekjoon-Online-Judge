#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer= "";
    
    int biggest = 0;
    int idx = 0;
    // k에 하나씩 더해서 k와 number size이 같아질 때까지
    for (int i=0; i<number.size(); i++) {
        if (number[i] > biggest) {
            biggest = number[i];
            idx= i; // 가장 큰 수의 인덱스를 기억한다.
        }
        
        
        // 최댓값을 갱신해주다가 k(멈춰서서 해당 최댓값을 answer에 넣어줘야 하는 위치)
        if (i==k) {
            answer.push_back(number[idx]);
            k++;
            i= idx; // 현재 인덱스 다음 위치부터 찾도록
            biggest =0; idx=0;
        }
        
    }
    
    return answer;
}