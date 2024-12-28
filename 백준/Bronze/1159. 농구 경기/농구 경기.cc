#include <iostream>
#include <vector>

using namespace std;
int alphabet[26]={0};
string str;
int N;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    
    for (int i=0; i<N; i++){
        cin >> str;
        alphabet[str[0]-'a']++;
    }

    int tmp=0;
    for (int i=0; i<26; i++){
        if (alphabet[i]>=5){
            cout << char(i+'a');
            tmp=1;
        }
    }

    str= "PREDAJA";
    if (tmp==0) cout << str;

   return 0;
}