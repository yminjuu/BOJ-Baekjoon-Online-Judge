#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    long long int T, N, M, count;
    
    cin >> T;
    for (int i=0; i<T; i++){
        count=1;
        int k=1;
        cin >> N >> M;
        for (int j=M; j > M-N; j--){
            count*=j;
            count/=k;
            k++;
        }
        cout << count << "\n";
    }
}