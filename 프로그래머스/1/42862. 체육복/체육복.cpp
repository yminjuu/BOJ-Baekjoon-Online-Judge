#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int student[35]; // 0으로 초기화

// 모범 답안 코드
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    // i는 벡터값 자체
    for (int i : reserve) student[i]+=1; // 여분이 있으므로
    for (int i : lost) student[i]-=1; // 구해야 함
    
    // 값이 0인 것 -> 빌리지도 / 구하지도 않음
    // 값이 1임 -> 빌려주기 가능
    // 값이 -1임 -> 구해야 함
    
    for (int i=1; i<=n; i++){
        if (student[i]==1) {
            if (student[i-1]==-1) student[i-1]+=1; // 앞에서부터 도와줌
            else if (student[i+1]==-1) student[i+1]+=1; // 뒤를 도와줌
        }
    }
    
    for (int i=1; i<=n; i++) if (student[i]!=-1) answer++;
    
    return answer;
}