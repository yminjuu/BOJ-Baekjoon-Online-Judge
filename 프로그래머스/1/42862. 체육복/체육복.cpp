#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    int isLost[30]= {0};
    int isUsed[30] = {0};
    
    for (int i=0; i<lost.size(); i++){
        for (int j=0; j<reserve.size(); j++){
            if (lost[i]==reserve[j]) {
                isLost[i]=1;
                isUsed[j]=1;
                answer++;
            }
            // erase, remove 함수로는 맨 마지막 원소를 삭제할 수가 없음
        }
    }

    for (int i=0; i<lost.size(); i++){
        if (isLost[i]==1) continue;
        
        int prevIdx=-1, nextIdx=-1;
        int tmp = lost[i]; 
        for (int j=0; j<reserve.size();j++){
            if (isUsed[j]==1) continue;
            if (tmp-1==reserve[j]) prevIdx= j;
            if (tmp+1==reserve[j]) nextIdx=j;
        }
        
        if (prevIdx==-1 && nextIdx==-1) continue;
        if (prevIdx!= -1) isUsed[prevIdx]= 1;
        else isUsed[nextIdx]=1;
        answer++;
        // 2) n-1, n+1 둘 다 빌리기 가능 => 앞에서 빌린다, answer 카운트
        // 3) n-1, n+1 둘 중 하나만 빌리기 가능 => 그걸 빌린다
        // 4) 둘 다 없다 => pass
    }
    
    return answer;
}