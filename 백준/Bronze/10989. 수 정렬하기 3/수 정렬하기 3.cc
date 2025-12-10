#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    int N, tmp;

    cin >> N;
    vector<int> vec(10001, 0);

    for (int i=0; i<N; i++){
        cin >> tmp;
        vec[tmp]+=1;
    }

    for (int i=1; i<=10000; i++){
        for (int j=0; j<vec[i]; j++){
            cout << i << "\n";
        }
    }
    
   return 0;
}