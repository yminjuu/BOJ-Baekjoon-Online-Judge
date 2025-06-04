#include <string>
#include <vector>
#include <queue>

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
    int lgth= words.size();
    vector<bool> visited(lgth, false);
    queue<pair<string,int>> q;
    q.push({begin,0});
    
    while (!q.empty()){
        string curr = q.front().first;
        int cnt= q.front().second;
        q.pop();
        
        if (curr==target) return cnt;
        
        for (int i=0; i<lgth; i++){
            if (!visited[i] && compStr(curr, words[i])){
                visited[i]= true;
                q.push({words[i], ++cnt});
            }
        }
    }
            
    return 0;
}