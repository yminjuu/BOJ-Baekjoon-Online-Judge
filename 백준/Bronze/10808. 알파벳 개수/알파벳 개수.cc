#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
string str;
int alphabet[26]= {0};

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
    
   getline(cin, str);

   for (int i=0; i<str.length(); i++){
        alphabet[str.at(i)-'a']++;
   }

   for (int i=0; i<26; i++){
     cout << alphabet[i] << " ";
   }

   return 0;
}