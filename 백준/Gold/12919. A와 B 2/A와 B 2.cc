#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   string a,b;
    cin >> a >> b;

    queue<string> q;
    q.push(b);

    int ans = 0;
    while (!q.empty() && q.front().length()>a.length()) {
        string tmp = q.front();
        q.pop();

        // 1. 끝이 A라면
        if (tmp[tmp.length()-1]=='A') {
            q.push(tmp.substr(0, tmp.length()-1));
        }

        // 2. 맨 앞이 B라면
        if (tmp[0]=='B'){
            reverse(tmp.begin(), tmp.end()); // tmp가 역방향 된 채 저장됨
            q.push(tmp.substr(0, tmp.length()-1));
        }
    }

    // a와 길이가 동일한 string들의 모음
    while (!q.empty() && q.front().length()==a.length()){
        string tmp =q.front();
        q.pop();
        
        if (tmp==a){
            ans=1;
            break;
        }
    }

    cout << ans;

   return 0;
}
