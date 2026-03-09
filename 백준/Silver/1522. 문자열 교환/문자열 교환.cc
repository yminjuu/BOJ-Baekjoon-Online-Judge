#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   string str;
    cin >> str;
    int N= str.length();

    int aCnt= 0;
    // 1. a의 개수 구하기
    for (int i=0; i<N; i++){
        if (str.at(i)=='a') aCnt++;
    }

    // 2. 슬라이딩 윈도우를 통해 a가 가장 많이 나오는 구간을 구한다
    
    // 시작값
    int sums[N+1];
    fill(&sums[0], &sums[N]+1, 0);
    for (int i=0; i<aCnt; i++){
        if (str[i]=='a') sums[0]++;
    }

    // start 값을 빼고 end 값을 더하며 슬라이딩 윈도우 진행
    for (int start= 0; start<N; start++){
        int end = start+aCnt; // 더해지는 값 인덱스
        if (end>=N) end-=N;

        int aDiff= 0;
        if (str[start]=='a') aDiff-=1;
        if (str[end]=='a') aDiff+=1;

        sums[start+1]= sums[start]+ aDiff;
    }

    int mx = 0;
    for (int i=0; i<N; i++){
        if (sums[i]>mx) mx= sums[i];
    }

    cout << aCnt-mx;

   return 0;
}
