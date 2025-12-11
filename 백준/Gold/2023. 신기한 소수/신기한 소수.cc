#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

static int N;
void DFS(int num);
bool isPrime(int num);

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    cin >> N;

    for (int i=2; i<=9; i++){
        DFS(i);
    }
    
   return 0;
}

void DFS(int num){
    if (isPrime(num)){
        string str = to_string(num);
        if (str.length()==N) {
            cout << str << "\n";
            return;
        }
        else {
            for (int i=1; i<=9; i++){
                DFS(num*10+i);
            }
        }
    }
    return;
}

bool isPrime(int num){
    if (num<=1) return false;
    for (int i=2; i<= sqrt(num); i++){
        if (num%i ==0) return false;
    }
    return true;
}