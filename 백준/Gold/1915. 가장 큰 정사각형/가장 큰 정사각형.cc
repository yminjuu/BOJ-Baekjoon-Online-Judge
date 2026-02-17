#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;
int arr[1004][1004];

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;

    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            char c;
            cin >> c;
            arr[i][j] = c-'0';
        }
    }

    long mx= 0;
    for (int i=1; i<=N; i++){
        for (int j=1; j<=M; j++){
            if ((arr[i][j-1]>=1 && arr[i-1][j]>=1) && (arr[i-1][j-1]>=1 && arr[i][j]>=1)){
                int tmp= min(min(arr[i-1][j-1], arr[i-1][j]), arr[i][j-1]);
                if ((arr[i][j-1]>=tmp && arr[i-1][j]>=tmp) && (arr[i-1][j-1]>=tmp && tmp!=0)){
                    // 값이 모두 같다면 -> 새로운 크기의 정사각형으로 확장
                    arr[i][j]= pow((sqrt(tmp)+1), 2);
                    if (mx<arr[i][j]) mx= arr[i][j];
                } else {
                    // 값이 다르다면 확장은 불가능
                    arr[i][j]= 4;
                }
            } else {
                if (arr[i][j]) arr[i][j]= 1;
            }
            if (mx<arr[i][j]) mx= arr[i][j];
        }
    }

    cout << mx;

   return 0;
}