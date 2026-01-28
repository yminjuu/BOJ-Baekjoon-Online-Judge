#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <numeric>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, ans;
   cin >> N;
    priority_queue<int, vector<int>> posPq;
    priority_queue<int, vector<int>, greater<int>> negPq; 
    int one=0; int zero=0;
    vector<int> ansNums;

    for (int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        if (tmp>1) posPq.push(tmp);
        else if (tmp<0) negPq.push(tmp);
        if (tmp==0) zero++;
        if (tmp==1) one++;
    }

    while (posPq.size()>1){
        int num1= posPq.top(); 
        posPq.pop();
        int num2= posPq.top(); 
        posPq.pop();
        ansNums.push_back(num1*num2);
    }
    while (negPq.size()>1){
        int num1= negPq.top(); negPq.pop();
        int num2= negPq.top(); negPq.pop();
        ansNums.push_back(num1*num2);
    }
    while (!posPq.empty()) {
        ansNums.push_back(posPq.top());
        posPq.pop();
    }
    if (!negPq.empty()) {
        if (zero==0){
            ansNums.push_back(negPq.top());
            negPq.pop();
        }
    }

    long long sum = accumulate(ansNums.begin(), ansNums.end(), 0);
    sum+=one;
    cout << sum;

   return 0;
}
