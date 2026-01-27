#include <iostream>
#include <algorithm>
using namespace std;

long long N, M, Mcnt, k=0;
int arr[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N); // 오름차순 정렬

    cin >> Mcnt;
    for (int i = 0; i < Mcnt; i++)
    {   
        cin >>M;
        k=0;
        int begin = 0, end = N - 1, mid = N / 2;
        while (begin <= end){
            
            mid=(begin+end)/2;
            
            if (arr[mid]==M) {
                k=1; break;
            }
            
            if (arr[mid]<M)
                begin=mid+1;
            if (M<arr[mid])
                end=mid-1;
            
        }
        cout << k << "\n";
    }
}