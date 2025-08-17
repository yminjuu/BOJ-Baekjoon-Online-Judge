#include <iostream>
#include <string>

using namespace std;
string str;
int N, sum=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    cin >> str;
    
    for (int i=0; i<N; i++){
        sum += str.at(i)-'0';
    }
    
    cout << sum;
}