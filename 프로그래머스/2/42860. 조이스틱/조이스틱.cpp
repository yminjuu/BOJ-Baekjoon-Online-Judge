#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name){
    int ans = 0, n = name.size();
    int minMov = n-1; // 일직선으로 그냥 이동
   
    for (int i=0; i<name.size(); i++){
        ans += min(name[i]-'A', abs(name[i]-'Z')+1);
    
        int firstA= i+1;
        while (name[firstA]=='A' && firstA < n) firstA++; 
        // 첫 A의 위치를 찾는다.
        
        // 첫번째 경우: 오 원점 왼
        // 두번째 경우: 왼 원점 오
        minMov = min(minMov, min(i+i+n-firstA, n-firstA+n-firstA+i));
    }
    
    ans += minMov;
    return ans;
}