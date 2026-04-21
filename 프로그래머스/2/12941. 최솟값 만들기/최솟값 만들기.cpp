#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end()); // 오름차순
    sort(B.begin(), B.end(), greater<int>()); // 내림차순
    
    int sum= 0;
    for (int i=0; i<A.size(); i++){
        int mult = A[i] * B[i];
        sum+=mult;
    }

    return sum;
}