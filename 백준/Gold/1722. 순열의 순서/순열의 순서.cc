#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N;
long perm[21];
bool visited[21]= {false};
// 24 6 2 1

void getPermut(){
    long k; 
    cin >> k;

    for (int i=1; i<=N; i++){
        for (int j=1, cnt=1; j<=N; j++){
            if (visited[j]) continue;
            if (k<= cnt*perm[N-i]) {
                k -= ((cnt-1) * perm[N-i]);
                cout << j << " ";
                visited[j]= true;
                break;
            }
            cnt++; 
        }
    }
}
void getSeqPermut(){
    long ans=1; 
    for (int i=N; i!=0; i--){
        int k;
        cin >> k;

        visited[k]= true;
        int tmp=0;
        for (int j=1; j<=N; j++){
            if (j==k) break; // 몇번째인지 구함
            if (!visited[j]) tmp++;
        }
        ans+= perm[i-1] * tmp;
    }
    cout << ans;
} 

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
    
    cin >> N;

    long mult=1; // 누적곱

    perm[0]= 1;
    for (int i=1; i<=N; i++){
        mult*=i;
        perm[i]=mult;
    }

    int num;
    cin >> num;
    if (num==1) getPermut();
    else getSeqPermut();

   return 0;
}