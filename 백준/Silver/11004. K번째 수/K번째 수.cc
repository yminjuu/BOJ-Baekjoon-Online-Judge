#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quickSort(vector<int> &A, int i, int j, int K);
int partition(vector<int> &A, int i, int j);

// 재귀를 통한 퀵정렬 구현
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, K;

   cin >> N >> K;

    vector<int> vec(N);
    for (int i=0; i<N; i++) cin >> vec[i];

    quickSort(vec, 0, N-1, K-1); 

    cout << vec[K-1];

   return 0;
}

void quickSort(vector<int> &A, int i, int j, int K){
    int pivotIdx = partition(A, i, j);
    
    if (pivotIdx == K) return;
    else if (pivotIdx < K) {
        quickSort(A, pivotIdx+1, j, K);
    }
    else quickSort(A, i, pivotIdx-1, K);
}

int partition(vector<int> &A, int i, int j){
    if (i+1 == j){
        if (A[i]>A[j]) swap(A[i], A[j]);
        return j;
    }
    
    swap(A[i], A[(i+j)/2]);

    int start = i+1; int end = j; int pivot = A[i];
    while (start<= end){
        while (start <= j && A[start]<pivot) start++;
        while (i+1 <= end && A[end]>pivot) end--;

        if (start<end) swap(A[start++], A[end--]);
        else break;
    }

    swap(A[i], A[end]);
    return end;
}