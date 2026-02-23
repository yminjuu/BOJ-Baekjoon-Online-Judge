#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>
#include <cstring>

using namespace std;

int N;

int orgState[100003];
string initial;
string fin;

long cnt= 0;
long ans = LLONG_MAX;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N >> initial >> fin;

    for (int i=0; i<initial.length(); i++){
        orgState[i]= initial.at(i)=='0' ? 0 : 1;
    }

   for (int j=0; j<2; j++){
       int state[100003];
       cnt =0;
       memcpy(state, orgState, sizeof(state));
       if (j==1) {
           cnt++;
           // 스위치를 누른다.
           state[0]= !state[0];
           state[1]= !state[1];
       }
        for (int i=0; i<N; i++){
       }
       for (int i=1; i<N-1; i++){
           int next = fin.at(i-1)=='0' ? 0 : 1;
            if (state[i-1]!=next){
                // 스위치를 눌러야 함 (i-1은 더이상 바뀌지 않음)
                cnt++;
                state[i-1]= !state[i-1];
                state[i]= !state[i];
                state[i+1]= !state[i+1];
                for (int i=0; i<N; i++){
       }
            } 
           // 이미 같다면 스위치를 누르지 않음
        }
      
       if (state[N-1]== (fin.at(N-1)=='0'?0:1) && state[N-2]==(fin.at(N-2)=='0'?0:1)){
            ans = min(ans, cnt);
       } else if (state[N-1]!= (fin.at(N-1)=='0'?0:1) && state[N-2]!=(fin.at(N-2)=='0'?0:1)){
           cnt++;
           ans= min(ans,cnt);
       }
   }

    if (ans==LLONG_MAX) cout << -1;
    else cout << ans;
    
   return 0;
}
