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
   
   string s;
    cin >> s;
    int lth = s.size();

    int zeroCnt=0, oneCnt=0;
    for (int i=0; i<lth; i++){
        if (s[i]=='0') zeroCnt++;
        else oneCnt++;
    }

    zeroCnt/=2; oneCnt/=2;
    string ans = s; // 정답을 넣을 문자열
    // 앞에서부터 1 제거
    for (int i=0; i<lth && oneCnt; i++){
        if (ans[i]=='1') {
            oneCnt--;
            ans[i]='2';
        }
    }
    
    // 뒤에서부터 0 제거
    for (int i=lth-1; i>=0 && zeroCnt; i--){
        if (ans[i]=='0') {
            zeroCnt--;
            ans[i]='2';
        }
    }

    // 출력
    for (int i=0; i<lth; i++){
        if (ans[i]=='0' || ans[i]=='1') cout << ans[i];
    }
    

   return 0;
}
