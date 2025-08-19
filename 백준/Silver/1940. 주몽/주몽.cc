#include <iostream>
#include <algorithm>

using namespace std;
int N,M, tmp, ans=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    vector<int> vec;

    for (int i=0; i<N; i++){
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());

    int start_index=0; 
    int end_index=N-1; 
    
    while (start_index < end_index){
        if (vec[start_index]+vec[end_index]<M){
            start_index++;
        } else if (vec[start_index]+vec[end_index]>M){
            end_index--;
        } else {
            ans++;
            start_index++;
            end_index--;
        }
    }
    
    cout << ans;
}