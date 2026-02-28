#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;
int N,K;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N >> K;
    vector<int> ans;

    deque<int> dq;
    for (int i=1; i<=N; i++){
        dq.push_back(i);
    }

    int cnt=1;
    while (!dq.empty()){
        if (cnt!=K) {
            dq.push_back(dq.front());
            dq.pop_front();
            cnt++;
        } else {
            ans.push_back(dq.front());
            dq.pop_front();
            cnt=1;
        }
    }

    cout << "<";
    for (int i=0; i<ans.size(); i++){
        cout << ans[i];
        if (i!=ans.size()-1) cout << ", ";
    }
    cout << ">";

   return 0;
}
