#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
string str, ans;
map <char, int > _map;
char oddApb='a';

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    getline(cin, str);
    bool evenLth = str.length()%2==0;

    for (int i=0; i<str.length(); i++) _map[str.at(i)]++;

    for (auto itr = _map.begin() ; itr!=_map.end(); itr++){

        while (itr->second!=0){
            int lth = ans.size();
            if (itr->second==1) {
                if (oddApb=='a') oddApb= itr->first;
                else {
                    cout << "I'm Sorry Hansoo";
                    return 0;
                }
                _map[itr->first]=0;
                }
            else {
                ans = ans.substr(0, lth/2) + itr->first + itr->first + ans.substr(lth/2, lth);
                _map[itr->first]-=2;
            }
        }
    }

    int lth = ans.size();
    if (oddApb!='a') ans = ans.substr(0, ans.size()/2) + oddApb + ans.substr(lth/2, lth);

    cout << ans;
   
   return 0;
}