#include <iostream>

using namespace std;

int N, M, i, j;
int num[100001]= {0};
long long sum[100001]= {0};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
   
    cin >> N >> M;
    
    for (int i=1; i<=N; i++){
        cin >> num[i];
        sum[i]= num[i] + sum[i-1];
    }
    
    for (int k=0; k<M; k++){
        cin >> i >> j;
        cout << (sum[j] - sum[i-1]) << "\n";
    }
}