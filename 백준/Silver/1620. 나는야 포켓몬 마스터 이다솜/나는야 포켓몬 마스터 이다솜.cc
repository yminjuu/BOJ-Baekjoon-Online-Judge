#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N, M; 
   cin >> N >> M;

    map<string,int> mp;
    string str[N+1];

   for (int i=1; i<=N; i++){
       string tmp;
       cin >> tmp;
       mp[tmp]= i;
       str[i]= tmp;
   }

    for (int i=1; i<=M; i++){
        string tmp;
        cin >> tmp;
        if (tmp[0] <= 'Z' && tmp[0] >= 'A') cout << mp[tmp] << "\n";
        else {
            int idx= stoi(tmp);
            cout << str[idx] << "\n";
        }
    }

   return 0;
}
