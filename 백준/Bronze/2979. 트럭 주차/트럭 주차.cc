#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int A,B,C;
int arr, dept, cost, sum=0;
int minute[101]= {0};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> A >> B >> C;

    for (int i=0; i<3; i++){
        cin >> arr >> dept;
        for (int j= arr; j<dept; j++){
            minute[j]++;
        }
    }

    for (int i=1; i<=100; i++){
        cost = minute[i]==3 ? C : minute[i]== 2 ? B : A;
        sum+= cost * minute[i];
    }

   cout << sum;
   
   return 0;
}