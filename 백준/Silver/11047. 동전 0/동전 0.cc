#include <iostream>
using namespace std;

int main() {
    int N, K, count=0;
    cin >> N >> K;
    int money [N];
    for (int i=0; i<N; i++){
        cin >> money[i];
        getchar();}
    for (int i=N-1; i>=0; i--){
        if (K/money[i]!=0)
            count+= K/money[i];
        K=K%money[i];
        if (K==0)
            break;
    }
    cout << count;
}