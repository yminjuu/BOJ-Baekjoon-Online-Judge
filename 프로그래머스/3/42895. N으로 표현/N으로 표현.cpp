#include <string>
#include <vector>
#include <unordered_set>
#include <climits>
#include <iostream>

using namespace std;

long nums[10];

int solution(int N, int number) {
    unordered_set<long> s[9];
    int answer = 0;
    
    nums[1]= N;
    for (int i=2; i<=8; i++){
        nums[i] = nums[i-1]*10+N;
    }
    
    for (int i=1; i<=8; i++){
        // s[i]를 완성
        s[i].insert(nums[i]);
        
        for (int j=1; j<=i/2; j++){
            int dpA = j; int dpB= i-j;
            
            // 2가지 set의 모든 조합을 확인
            for (auto a : s[dpA]){
                for (auto b: s[dpB]){
                    s[i].insert(a+b);
                    s[i].insert(a-b);
                    s[i].insert(b-a);
                    if (a!=0 && b!=0) s[i].insert(a*b);
                    
                    if (b!=0) s[i].insert(a/b);
                    if (a!=0) s[i].insert(b/a);
                }
            }
        }
        
        for (auto num: s[i]){
            if (num==number) {
                return i;
            }
        }
    }
    
    return -1;
}