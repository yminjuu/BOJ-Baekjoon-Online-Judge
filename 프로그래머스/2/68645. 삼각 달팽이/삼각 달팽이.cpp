#include <string>
#include <vector>
#include <iostream>

using namespace std;

int colIdxs[600000][2];
int accumSum[600000]; // 누적합 
int arr[600000]; // 정답 저장

vector<int> solution(int n) {
    vector<int> answer;
    
    accumSum[0]= 0;
    for (int i=1; i<=n; i++){
        accumSum[i]= accumSum[i-1] + i;
        colIdxs[i][0]= 0;
        colIdxs[i][1]= i-1;
    }
    int totalNums= accumSum[n];
    
    int num=1;
    int s= 1; int e= n;
    int direction = 1;
    while (s<=e){
        if (direction == 1) {
            for (int r=s; r<=e && num<=totalNums; r++){
            int colIdx;
            colIdx= colIdxs[r][0]; // 맨 앞
            colIdxs[r][0]++;
            
            // 채우고
            arr[accumSum[r-1] + 1 + colIdx]= num++;
        }
        // 맨 밑 행 처리
        for (int i= colIdxs[e][0]; i<= colIdxs[e][1] && num<=totalNums; i++){
            // 처음부터 끝까지 다 채운다
            arr[accumSum[e-1] + 1 + i] = num++;
        }
            s++; e--;
        }
        
        if (direction == -1){
            for (int r=e; r>=s && num<=totalNums; r--){
            int colIdx = colIdxs[r][1]; // 맨 뒤
            colIdxs[r][1]--;
            
            // 채우고
            arr[accumSum[r-1] + 1 + colIdx]= num++;
        }
            s++; 
        }
        
        direction = (direction == 1) ? -1 : 1;
    }
    
    for (int i=1; i<=accumSum[n]; i++){
        answer.push_back(arr[i]);
    }
    
    return answer;
}