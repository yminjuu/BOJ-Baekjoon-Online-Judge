#include <string>
#include <vector>
#include <stack>

using namespace std;

// DFS의 종료 조건: 뻗을 수 있는 만큼 전부 탐색 후 시작점으로 다시 돌아온 경우 => 하나의 네트워크 완성
// DFS의 반복해서 시작 조건을 찾으려면: 인접 배열을 돌면서 내가 아니고/ 값이 1이고/ visited 하지 않았어야 한다.
// visited 배열을 사용해야됨
// 마지막에 네트워크 count: visited 하지 않은 배열을 세서 그것도 마지막으로 count

// DFS
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int visited[201]= {0};
    stack<int> stck;
    
    for (int i=0; i<n; i++){
        if (!visited[i]) {stck.push(i); visited[i]=1;  answer++;} // 새로운 시작점
        while (!stck.empty()){
            int basis = stck.top(); stck.pop();
            for (int j=0; j<n; j++){
                if (!visited[j] && computers[basis][j] && j!=basis) {
                    visited[j]=1; stck.push(j);
                }
            }
        }
    }
    
    return answer;
}