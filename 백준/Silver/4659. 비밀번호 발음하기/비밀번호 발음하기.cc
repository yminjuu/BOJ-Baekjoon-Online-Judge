#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
string str, res;
char rec;
char vowl[5] = {'a', 'e', 'i', 'o', 'u'};
int isVowl[26]= {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};


int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   while (true){
        cin >> str;
        if (str=="end") break;
        res= "not acceptable";
        stack <char>stck;

        for (int i=0; i<5; i++){
            if (str.find(vowl[i])!=string::npos) res="acceptable";
        }

        stck.push(isVowl[str.at(0)-'a']);
        for (int i=1; i<str.length(); i++){
            int tmp= isVowl[str.at(i)-'a'];
            if (stck.top()!=tmp) {
                while( !stck.empty() ) 
                    stck.pop();
            } else if (stck.size()==2){
                res= "not acceptable";
                break;
            } else {
                if (str.at(i-1)==str.at(i) && str.at(i)!='e' && str.at(i)!='o'){
                    res= "not acceptable";
                    break;
                }
            }
            stck.push(tmp);
        }
        
        cout << "<" << str << ">" << " is " << res << "." << endl;
   }
   
   return 0;
}