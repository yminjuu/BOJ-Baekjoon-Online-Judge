#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;

int maxLength;
int N;
long A[1000002];
long B[1000002];
long dp[1000002];

int binarysearch(int l, int r, int now){
    int mid;

    while (l<r){
        mid = (l+r)/2;
        if (B[mid]<now){
            // 크면 들어갈 수 있음, 일단 포함시킴
            l= mid+1;
        } else {
            // 내가 더 작음
            r= mid;
        }
    }

    return l;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    cin >> N;

    for (int i=1; i<=N; i++){
        cin >> A[i];
    }

    dp[1]= 1; maxLength=1; B[1]= A[1];
    for (int i=2; i<=N; i++){
        // 나보다 작은 원소가 끝인지 확인
        if (B[maxLength]<A[i]){
            B[++maxLength]= A[i];
            dp[i]= maxLength;
        } else {
            int index = binarysearch(1, maxLength, A[i]);
            B[index] = A[i];
            dp[i]= index;
        }
    }

    cout << maxLength << "\n";
    vector<int> ans;    
    for (int i=N; i>=1; i--){
        if (dp[i]==maxLength) {ans.push_back(A[i]); maxLength--;}
    }

    for (int i=ans.size()-1; i>=0; i--){
        cout << ans[i] << " ";
    }
}
