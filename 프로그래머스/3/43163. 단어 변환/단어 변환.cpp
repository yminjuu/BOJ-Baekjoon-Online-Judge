#include <string>
#include <vector>
#include <stack>

using namespace std;

bool compStr(string A, string B){
    int sum=0;
    for (int i=0; i<A.length(); i++){
        if (A[i]!=B[i]) sum++;
    }
    if (sum==1) return true;
    else return false;
}

// 전체: BFS 사용
// 문제: 특정 문자열 간 얼마나 차이나는지를 어떻게 하면 효율적으로 판단할까?
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int targetSz = target.length();
    int lgth= words.size();
    stack<pair<int,int>> stck;
    
    // 시작점을 찾는 과정
    for (int i=0; i<lgth; i++){
        
        // 알맞은 시작점으로부터 시작
        if (compStr(begin, words[i])){
            // 해결 가능할 때까지 DFS
            int visited[50]= {0}; visited[i]=1;
            stck.push(make_pair(i, 1)); // 인덱스와 카운트
            
            while (!stck.empty()){
                int currIdx= stck.top().first; 
                string currStr= words[currIdx]; visited[currIdx]=1; int currCnt= stck.top().second;
                stck.pop();
                
                // 정답인지 검증
                if (currStr==target) return currCnt;
                for (int j=0; j<lgth; j++){
                    if (!visited[j] && compStr(currStr, words[j])){
                        // 방문 안 했고 하나 차이 나면 스택에 넣기
                        stck.push(make_pair(j, currCnt+1));
                    }
                }
            }
        }
    }
    
    return 0;
}