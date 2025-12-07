#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, tmp; 

   cin >> N;
    vector<pair<int, int> > vec;

    for (int i=0; i<N; i++){
        cin >> tmp;
        vec.push_back(make_pair(tmp, i));
    }

    sort(vec.begin(), vec.end());

    int mx= 0;
    for (int i=0; i<N; i++){
        int absDiff = vec[i].second-i;
        if (mx < absDiff) mx = absDiff; 
    }

    cout << mx+1;

   return 0;
}