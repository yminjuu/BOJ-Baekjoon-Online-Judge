#include <iostream>
#include <vector>
#include <deque>

using namespace std;
typedef pair<int,int> Node; // 타입 정의
int N,L,tmp;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    deque<Node> deq;

    cin >> N >> L >> tmp;
    deq.push_back({0, tmp});
    ans.push_back(tmp);
    
    int front = 0;

    for (int i=1; i<N; i++){
        front = i>=L ? i-L+1 : 0;
        if (deq.front().first < front) deq.pop_front();

        cin >> tmp;
        if (!deq.empty() && deq.back().second >= tmp) {
            while (!deq.empty() && deq.back().second >= tmp) deq.pop_back();
        } 
        deq.push_back({i, tmp});
        ans.push_back(deq.front().second);
    }

    for (int i=0; i<ans.size(); i++){
        cout << ans.at(i) << " ";
    }
}