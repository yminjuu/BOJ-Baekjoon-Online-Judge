#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);

    queue<int> q;

    int N;
    cin >> N;

    for (int i=0; i<N; i++){
        q.push(i+1);
    }

    for (int i=1 ; i<N ; i++){
        q.pop();
        int k = q.front();
        q.pop();
        q.push(k);
    }
    cout << q.front();
    return 0;
}   