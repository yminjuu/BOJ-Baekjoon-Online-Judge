#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
static vector<long> A, L, R;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
    cin >> N;

    A.resize(N+2);
    L.resize(N+2);
    R.resize(N+2);
    // L[i], R[i]의 의미: i번째 원소를 "포함하는" 합 배열 중 가장 큰 것

    for (int i=1; i<=N; i++){
        cin >> A[i];
    }

    // 왼쪽 기준 합 배열
    L[0]= 0; long mx_base= A[1]; // 초깃값: 하나는 선택해야 한다
    for (int i=1; i<=N; i++){
        // 새로 시작하거나 앞의 연속 배열을 잇거나
        L[i]= max(L[i-1]+ A[i], A[i]);
        mx_base= max(mx_base, L[i]);
    }

    // 오른쪽 기준 합 배열
    R[N+1]= 0;
    for (int i=N; i!=0; i--){
        R[i] = max(R[i+1]+A[i], A[i]);
    }

    // 제거 로직은 따로 뺴준다
    long mx = mx_base;

    // i 범위: 양 끝을 제거하는 경우
    for (int i=2; i<N; i++){
        // i를 제거하는 경우
        mx = max(mx, (long)L[i-1]+R[i+1]);
    }

    cout << mx;

   return 0;
}
