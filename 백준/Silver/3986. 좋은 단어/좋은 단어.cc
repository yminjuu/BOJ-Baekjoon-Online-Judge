#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N, cnt=0;
string str;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

   cin >> N;
   while (N--){
    stack <int>stck;
        cin >> str;
        for (int i=0; i<str.length(); i++){
            if (stck.size()!=0 && stck.top()==str.at(i)) stck.pop(); 
            else stck.push(str.at(i));
        }
        if (stck.size()==0) cnt++;
   }
   
   cout << cnt; 
   return 0;
}