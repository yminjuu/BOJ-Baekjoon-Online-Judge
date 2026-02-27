#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

string goal;
int answer = INT_MAX;
int sz;
vector<string> gWords;
int visited[52];

void dfs(string start, int cnt) {
    if (start==goal) {
        answer = min(cnt, answer);
        return;
    }
    
    // 1글자만 다른 거 찾아서 dfs 진행
    for (int i=0; i< gWords.size(); i++){
        int tmp=0;
        if (visited[i]) continue;
        for (int j=0; j< sz; j++){
            if (start[j]!= gWords[i][j]) tmp++;
        }
        if (tmp==1) {
            visited[i]= 1;
            dfs(gWords[i], cnt+1);
            visited[i]=0;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    gWords= words;
    sz= begin.length();
    goal= target;
    
    for (int i=0; i<words.size(); i++){
        int cnt=0;
        for (int j=0; j<sz; j++){
            if (begin[j]!=words[i][j]) cnt++;
        }
        if (cnt==1) {
            visited[i]= 1;
            dfs(words[i], 1);
            visited[i]=0;
        }
    }
  
    if (answer==INT_MAX) return 0;
    else return answer;
}