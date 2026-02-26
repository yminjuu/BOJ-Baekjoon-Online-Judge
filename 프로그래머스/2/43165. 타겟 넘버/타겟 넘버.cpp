#include <string>
#include <vector>

using namespace std;

vector<int> number;
int tar;
int ans=0;

void dfs(int n, int curr){
    // 끝까지 도달
    if (n==number.size()){
        if (curr==tar) ans++;
        return;
    }
    
    int tmp = curr;
    dfs(n+1, curr+number[n]);
    dfs(n+1, curr-number[n]);
}

int solution(vector<int> numbers, int target) {
    number= numbers;
    tar= target;
    
    dfs(0, 0);
  
    return ans;
}