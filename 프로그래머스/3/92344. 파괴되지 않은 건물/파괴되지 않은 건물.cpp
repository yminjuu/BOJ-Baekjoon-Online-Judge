#include <string>
#include <vector>
#include <iostream>

using namespace std;
int N, M;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    N= board.size(); M= board[0].size();
    vector<vector<int>> arr(N+1, vector<int>(M+1, 0));
    
    for (int i=0; i< skill.size(); i++){
        int type= skill[i][0];
        int r1= skill[i][1]; int c1= skill[i][2];
        int r2= skill[i][3]; int c2= skill[i][4];
        int degree= skill[i][5];
        
        if (type==1) degree*= -1;
        
        int colLth = r2-r1;
        int rowLth= c2-c1;
        
        // 이모스법 사용 -> 좌상단 꼭짓점 체크, 벗어난 꼭짓점 3곳 체크
        arr[r1][c1]+= degree;
        arr[r1][c1+rowLth+1]-= degree;
        arr[r1+colLth+1][c1]-= degree;
        arr[r1+colLth+1][c1+rowLth+1]+= degree; // 뺄셈끼리 맞닿는 지점 => 더해줌
    }
    
    // 0열 따로 처리
    for (int i=1; i<N; i++){
        arr[i][0] = arr[i-1][0]+ arr[i][0];
    }
    
    // 0행 따로 처리
    for (int i=1; i<M; i++) arr[0][i]= arr[0][i-1] + arr[0][i];
    
    for (int i=1; i<N; i++){
        for (int j=1; j<M; j++){
            arr[i][j] = arr[i-1][j]+arr[i][j-1] - arr[i-1][j-1] + arr[i][j];
        }
    }
    
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if ((arr[i][j] + board[i][j])>0) answer++;
        }
    }
    
    return answer;
}