#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;
int arr[1100000]; // 0으로 초기화

bool isPalindrome(int target){
    string str = to_string(target);

    for (int i=0; i<=str.length()/2; i++){
        int oppIdx = str.length()-1-i;
        if (str[i]!=str[oppIdx]) return false;
    }
    return true;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    arr[1]= 1; // 1은 소수가 아님
    for (int i=2; i<=sqrt(1100000); i++){
        if (arr[i]==0){
            for (int j=i*i; j<=1100000; j=j+i){
                arr[j]= 1;
            }
        }
    }

    for (int i=N; i<=1100000; i++){
        if (arr[i]==0 && isPalindrome(i)){
            cout << i;
            return 0;
        }
    }
    
   return 0;
}
