#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>

using namespace std;
using p= pair<char,int>;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   string str, explode;
    cin >> str >> explode;

    stack<p> stck;

    int idx=0;
    for (int i=0; i<str.length(); i++){
        if (explode.at(idx)==str.at(i)){
            idx++;
        } else if (explode.at(0)==str.at(i)){
            idx=1;
        } else idx=0;
        stck.push({str.at(i), idx});

        if (idx==explode.length()){
            idx=0;
            for (int i=0; i<explode.length(); i++) stck.pop();

            if (!stck.empty())
                idx = stck.top().second;
        }
    }

    string ans=""; // string을 vector처럼 사용
    while (!stck.empty()){
        ans.push_back(stck.top().first);
        stck.pop();
    }

    reverse(ans.begin(), ans.end());
    if (ans.length()==0) ans="FRULA";
    cout << ans;

   return 0;
}
