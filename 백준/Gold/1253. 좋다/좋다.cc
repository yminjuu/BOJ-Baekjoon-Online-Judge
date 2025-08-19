#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, tmp;
int ans =0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    vector<int> vec;

    for (int i=0; i<N; i++){
        cin >> tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());

    for (int k=0; k<N; k++){
        int i=0;
        int j=N-1; 
        while (i<j){
            int sum= vec[i]+vec[j];
            if (sum<vec[k]){
                i++;
            } else if (sum>vec[k]){
                j--;
            } else {
                if (i!=k && j!=k){
                    ans++;
                    break;
                } else if (i==k){
                    i++;
                } else if (j==k){
                    j--;
                }
            }
        }
    }

    cout << ans;
}