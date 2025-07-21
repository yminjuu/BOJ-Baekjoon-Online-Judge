#include <iostream>

using namespace std;

int main() {
    int N,count, max5=0;
    cin >> N;
    if (N/5>0){
        max5 = N/5;
        for (int i=max5; i>0; i--){
        int newN= N-5*i;
        if (newN%3==0){
            count=i+newN/3;
            cout << count;
            return 0;}}
        }
    if (N%3==0){
        cout << N/3;
        return 0;
    }
    cout << "-1";
    return 0;
    }