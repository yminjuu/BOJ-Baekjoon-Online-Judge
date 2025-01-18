#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> height;
int tmp,sum=0;
int realI, realJ;

void check(){
    for (int i=0; i<8; i++){
        for (int j=i+1; j<9; j++){
            tmp= sum;
            tmp-=height[i]; tmp-=height[j];
            realI= height[i];
            realJ= height[j];
            if (tmp==100) {
                remove(height.begin(), height.end()+1, realI);
                remove(height.begin(), height.end()+1, realJ);
                return;
            }
        }
    }
    return;
}

int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   for (int i=0; i<9; i++){
    cin >> tmp;
    height.push_back(tmp);
    sum+=tmp;
   }

    check();

    sort(height.begin(), height.end());
    for (int i=0; i<9; i++){
        if (height[i]!=0) cout << height[i] << "\n";
    }

   return 0;
}