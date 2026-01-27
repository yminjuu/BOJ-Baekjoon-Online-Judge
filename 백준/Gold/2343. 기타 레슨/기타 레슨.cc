#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N,M; 
vector<int> vec;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   cin >> N >> M;

   int tmp; int mx=0; int sum=0;
   for (int i=0; i<N; i++){
        cin >> tmp;
        sum+=tmp;
        vec.push_back(tmp);
        if (vec[mx]<tmp) mx= i;
    }

   long i = vec[mx];
   long j = sum; 

   while (i<j) {
    long mid = (i+j)/2;

    int cnt= 1; int space=0;
    for (int k=0; k<N; k++){
        if (space+vec[k]>mid) {
            cnt++; space =0;
        }
        space+=vec[k];
    }
    if (space>mid) cnt++;
    
    if (cnt>M) {
        i= mid+1;
    } else {
        j= mid;
    }
   }

   cout << i;

   return 0;
}
