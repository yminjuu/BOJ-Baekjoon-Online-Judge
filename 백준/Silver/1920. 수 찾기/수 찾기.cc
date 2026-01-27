#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N,M;
vector<int> vec; // N 보관
void find(int tmp);

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N;
   int tmp;
   for (int i=0; i<N; i++){
        cin >> tmp;
        vec.push_back(tmp);
   }

   sort(vec.begin(), vec.end()); // 오름차순 기본

   cin >> M;
   for (int i=0; i<M; i++){
    cin >> tmp;
    find(tmp);
   }

   return 0;
}

void find(int tmp){
    int i=0; int j= vec.size()-1;

    while (i<=j){
        int mid = (i+j)/2;
        if (vec[mid]> tmp){
            j=mid-1;
        } else if (vec[mid]<tmp) {
            i=mid+1;
        } else {
            cout << 1 << "\n";
            return;
        }
    }
    cout << 0 << "\n";
}
