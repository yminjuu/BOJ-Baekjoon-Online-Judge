#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T, N;

void fashion(){
    string tmp, type;
    vector <pair<string, int> > item;

    cin >> N;
    for (int i=0; i<N; i++){
        cin >> tmp >> type;
        bool flag= false;
        for (int j=0; j<item.size(); j++){
            if (item.at(j).first==type) { item.at(j).second++; flag=true; break;}
        }        
        if (!flag) {
            pair<string,int> newPair;
            newPair.first= type;
            newPair.second= 2;
            item.push_back(newPair);
        }
    }

    int sum=1;
    for (int i=0; i<item.size(); i++){
        sum*=item.at(i).second;
   }
   cout << sum-1 << endl; 
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> T;

   while (T--) fashion();
   
   return 0;
}