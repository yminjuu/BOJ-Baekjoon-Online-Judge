#include <vector>
#include <string>
#include <climits>
#include <iostream>
using namespace std;

int calc(int x, int y, string op){
    if (op=="+") return x+y;
    else return x-y;
}

int solution(vector<string> arr)
{
    int N = arr.size();
    int answer = -1;
    
    int max_dp[205][205]; // 숫자 기준으로 생각 
    int min_dp[205][205];
    
    fill(&max_dp[0][0], &max_dp[204][204]+1, INT_MIN);
    fill(&min_dp[0][0], &min_dp[204][204]+1, INT_MAX);
    
    // max_dp, min_dp 초기화
    for (int i=0; i<N; i+=2){
        // 짝수에만 들어갈 것임
        max_dp[i][i]= stoi(arr[i]);
        min_dp[i][i]= stoi(arr[i]);
    }
    
    // arr 배열 기준 구간 크기: 3부터 시작, 2씩 증가, N까지
    for (int sec=3; sec<=N; sec+=2){
        for (int start=0; start+sec<=N; start+=2){
            // 시작 인덱스 
            int end = start+sec-1;
            // start, end는 항상 짝수다
            // cout << start << " " << end<<"\n";
            
            // [start,end]에서 구분값 k를 사용한다 => k는 연산자의 위치이며 홀수값이다.
            for (int k=start+1; k<end; k+=2){
                // start~k / k+1~end
                if (arr[k]=="+"){
                    max_dp[start][end] = max(max_dp[start][end], calc(max_dp[start][k-1], max_dp[k+1][end], "+"));
                    min_dp[start][end] = min(min_dp[start][end], calc(min_dp[start][k-1], min_dp[k+1][end], "+"));
                } else {
                    max_dp[start][end] = max(max_dp[start][end], calc(max_dp[start][k-1], min_dp[k+1][end], "-"));
                    min_dp[start][end] = min(min_dp[start][end], calc(min_dp[start][k-1], max_dp[k+1][end], "-"));
                }
            }
        }
    }
    
    return max_dp[0][N-1];
}
