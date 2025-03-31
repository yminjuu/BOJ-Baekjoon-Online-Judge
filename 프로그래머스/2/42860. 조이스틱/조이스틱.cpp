#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name){
    int ans = 0, n = name.size();
    int leftRightMove = n-1;
    for(int x = 0; x < n; x++){
        ans += min(name[x]-'A', abs(name[x]-'Z')+1);
        int y = x + 1; 
        while( y < n && name[y] == 'A') y++;
        leftRightMove = min( leftRightMove, min( x+x+(n-y), x+(n-y)+(n-y) ) );
    }
    ans += leftRightMove;
    return ans;
}