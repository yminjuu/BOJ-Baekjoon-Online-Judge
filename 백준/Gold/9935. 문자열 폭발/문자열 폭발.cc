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
   
   string ans="";
    string str, explode;
    cin >> str >> explode;
    int len = explode.length();

    for (int i=0; i<str.length(); i++){
        ans.push_back(str.at(i));

        if (str.at(i)==explode.back() && ans.length()>= len){
            // 끝이 같다면 검사 시작
            bool isSame= true;
            for (int j=0; j<len; j++){
                if (ans[ans.length()-1-j]!= explode[len-1-j]) {
                    isSame= false;
                    break;
                }
            }
            
            if (isSame){
                for (int j=0; j<len; j++){
                    ans.pop_back();
                }
            }
        }
    }

    if (ans.length()==0) cout << "FRULA";
    else cout << ans;

   return 0;
}
