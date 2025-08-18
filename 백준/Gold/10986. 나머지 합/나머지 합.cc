#include <iostream>
#include <vector>

using namespace std;

int N,M, tmp;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    vector<long> sum(N,0);
    vector<long> remainder(M,0);

    cin >> sum[0];
    for (int i=1; i<N; i++){
        cin >> tmp;
        sum[i]= sum[i-1] + tmp;
    }

    for (int i=0; i<N; i++){
        sum[i] = sum[i] % M;
        remainder[sum[i]]++; 
    }

    long long ans=0;
    ans+= remainder[0];
    for (int i=0; i<M; i++){
        ans += (remainder[i]*(remainder[i]-1)/2);
    }
    cout << ans;
}