#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name){
    int upDownMove[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int ans = 0, n = name.size();
    int leftRightMove = n-1;
    for(int x = 0; x < n; x++){
        ans += upDownMove[name[x]-'A'];
        int y = x + 1; 
        while( y < n && name[y] == 'A') y++;
        leftRightMove = min( leftRightMove, min( x+x+(n-y), x+(n-y)+(n-y) ) );
    }
    ans += leftRightMove;
    return ans;
}