#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <cstdio>

using namespace std;
vector<int> colorCnt;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    int M; // 색상 개수
    cin >> M;
    colorCnt.resize(M+1);
    
    int total=0; 
    for (int i=1; i<=M; i++){
        cin >> colorCnt[i];
        total+=colorCnt[i];
    }

    int K;
    cin >> K;

    long double sum = 0;
    for (int i=1; i<=M; i++){
        long double perc= 1;
        for (int k=0; k<K; k++){
            // k번 반복
            perc*= ((long double)(colorCnt[i]-k) / (total-k));
        }
        sum+=perc;
    }

    cout << fixed;
    cout.precision(9);
    cout << sum;

   return 0;
}
