#include <iostream>
#include <limits.h>
#include <vector>
#include <cstdlib>

using namespace std; 

int n, w, L, k;
int sum=0, total =1;
int front=0, back=0;
vector<pair<int, int> > vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> w >> L;
    for (int i=0; i<n; i++){
        cin >> k;
        vec.push_back(make_pair(k, w));
    }

    int chk =0;
    for (int i=0; i<n; i++){
        chk=0;
        while (vec[i].first+sum>L && front<=back){ 
            chk=1;
            total++;
            for (int j=front;j<=back; j++){
                if (--vec[j].second<0){
                    front = j+1;
                    sum -= vec[j].first;
                };
            }
        }
        back=i;
        sum+=vec[i].first;
        if (chk==0) {
            total++;
            for (int j=front; j<=back; j++){
                if (--vec[j].second<0){
                    front= j+1;
                    sum -= vec[j].first;
                };
            }
        }
        else vec[i].second--;
    }

    if (vec[n-1].second>0) total+= vec[n-1].second;
    
    cout << total;

    return 0;
}