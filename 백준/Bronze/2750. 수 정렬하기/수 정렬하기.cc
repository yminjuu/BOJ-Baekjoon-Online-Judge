#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N; 
   int arr[1001]= {0,};

   cin >> N;

    for (int i=0; i<N; i++){
        int num;
        cin >> num;
        arr[i] = num;
    }

    for (int i=0; i<N-1; i++){ 
        for (int j=0; j<N-i-1; j++){
            if (arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }

    for (int i=0; i<N; i++) cout << arr[i] << "\n";


   return 0;
}