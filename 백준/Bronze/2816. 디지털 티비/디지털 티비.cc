#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n;
int kbs[2];
int pos[2]= {0,1};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    cin >> n;

    string str;
    for (int i=0; i<n; i++){
        cin >> str;
        if (str.length()==4 && str.substr(0,3)=="KBS"){
            if (str.at(3)=='1') kbs[0]= i;
            else kbs[1]= i;
        }
    }

     int currPos= 0;
    for (int i=0; i<2; i++){
        // 내려가기
        while (currPos<kbs[i]){
            cout << 1;
            currPos++;
        }
    
        // 가지고 위에 올려놓기
        while (pos[i] < currPos){
            cout << 4;
            currPos--;
        }
       
        // 만약 kbs2의 위치가 바뀌었다면
        if (kbs[0] > kbs[1]) {
            // 하나 밀렸음
            kbs[1]++;
        }
    }

   return 0;
}
