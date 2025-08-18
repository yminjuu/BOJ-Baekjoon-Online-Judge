#include <iostream>
#include <vector>
int N, tmp, mx=0;
float ans= 0.0;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    vector<int> vec;
    for (int i=0; i<N; i++){
        cin >> tmp;
        vec.push_back(tmp);
    }
    
    for (int i=0; i<N; i++){
        if (vec[i]>mx) mx= vec[i];
        ans+= vec[i];
    }
    
    ans = (ans / mx * 100) / N;
    cout << ans;
}