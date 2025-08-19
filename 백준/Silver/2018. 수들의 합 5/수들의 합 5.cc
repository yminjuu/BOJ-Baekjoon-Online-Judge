#include <iostream>

using namespace std;
int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    int start_index= 1; int end_index= 1;
    int ans = 1;
    int sum= 0;
    
    while (start_index< N && end_index <= N){
        if (sum==N) {
            ans++;
            sum -= start_index++;
        } else if (sum < N){
            sum+= end_index++;
        } else {
            sum-= start_index++;
        }
    }
    
    cout << ans;
}