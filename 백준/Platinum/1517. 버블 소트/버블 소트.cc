#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge_sort(int s, int e);
static vector<int> A; 
static vector<int> R;
static long swapCnt= 0;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;

    cin >> N;
    A = vector<int>(N+1, 0);
    R = vector<int>(N+1, 0);

    for (int i=0; i<N; i++){
        cin >> A[i];
    }

    merge_sort(0, N-1);

    cout << swapCnt;

   return 0;
}

void merge_sort(int s, int e){
    if (s==e) return;

    int m = s+ (e-s)/2;
    merge_sort(s, m);
    merge_sort(m+1, e);

    int s1=s; int s2= m+1;
    int pos = s; // 원본 배열의 기준점

    while (s1<=m && s2<=e) {
        if (A[s1]<=A[s2]){
            R[pos++] = A[s1++];
        } else {
            swapCnt+= (s2-pos);
            R[pos++]= A[s2++];
        }
    }

    while (s1<=m){
        R[pos++]= A[s1++];
    }

    while (s2<=e){
        R[pos++]=  A[s2++];
    }

    for (int i=s; i<= e; i++){
        A[i] = R[i];
    }

    return;
}