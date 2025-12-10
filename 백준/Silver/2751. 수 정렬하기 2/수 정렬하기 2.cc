#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge_sort(int s, int e);
static vector<int> A;
static vector<int> R;

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

    for (int i=0; i<N; i++){
        cout << A[i] << "\n";
    }

   return 0;
}

void merge_sort(int s, int e){
    if (s==e) return;

    // (1) 분할
    int m = s+ (e-s)/2;
    merge_sort(s, m); // s ~ m는 정렬 완료
    merge_sort(m +1, e); // m+1 ~ e 정렬 완료

    int pos = s; // s부터 시작
    int s1= s; // 끝 기준: m 
    int s2= m+1; // 끝 기준: e

    while (s1<=m && s2<=e) {
        if (A[s1]<A[s2]){
            R[pos++] = A[s1++];
        } else {
            R[pos++] = A[s2++];
        }
    }

    int basis = s1>m ? s2 : s1;
    int end = s1>m ? e : m;
    while (pos<=e && basis<=end){
        R[pos++] = A[basis++];
    }

    for (int i=s; i<=e; i++){
        A[i] = R[i];
    }

    return;
}