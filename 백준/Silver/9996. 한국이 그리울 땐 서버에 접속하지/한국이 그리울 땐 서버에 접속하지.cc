#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, idx;
string temp, pattern= "";
string firstStr, lastStr="";

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> N;
   cin >> pattern;

   idx= pattern.find("*");
   firstStr= pattern.substr(0, idx);
   lastStr= pattern.substr(idx+1, pattern.length());
   
   for (int i=0; i<N; i++){
        cin >> temp;
        size_t firstFound = temp.find(firstStr);

        size_t lastFound = temp.find(lastStr, temp.length()-lastStr.length());

        if (firstFound!= string::npos && lastFound!= string::npos && firstFound==0 && firstStr.length()<=lastFound){
            cout << "DA" << endl;
        } else cout << "NE" << endl;
   }

   return 0;
}