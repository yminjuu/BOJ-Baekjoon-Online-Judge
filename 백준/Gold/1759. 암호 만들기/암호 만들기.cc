#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std; 

int L,C;
char c;
vector<char> vec;
vector<char> ans;

int vowl[5] = {0,4,8,14,20};

void choose(int base){
    int vowlCnt= 0;
    if (ans.size()==L){
        for (int j=0; j<L; j++){
            for (int k=0; k<5;k++){
                if (ans[j]-'a'==vowl[k]){
                    vowlCnt++;
                    break;
                }
            }
        }
        if (vowlCnt==0 || (L-vowlCnt)<2) return;
        for (int j=0; j<L; j++){
            cout << ans[j];
        }
        cout << "\n";
        return;
    }
        for (int i=base; i<C; i++){
            ans.push_back(vec[i]);
            choose(i+1);
            ans.pop_back();
        }
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

   cin >> L >> C;

   for (int i=0; i<C; i++){
        cin >> c;
        vec.push_back(c);
   }
   sort(vec.begin(), vec.end());

    choose(0);    
    return 0;
}