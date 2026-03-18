#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
    string str;
    cin >> str;

    string explode;
    cin >> explode;

    deque<int> vec; // idx를 저장

    string arr[str.length()+1]; // 나까지 포함되는 curr 문자열을 저장한다.

    int N= str.length();
    string curr="";
    for (int i=0; i<N; i++){
        if (str.at(i)== explode.at(curr.length())){
            curr+= str.at(i);
        } else if (str.at(i)==explode.at(0)) {
            curr= str.at(i);
        } else {
            // 초기화
            curr= "";
        }
        arr[i]= curr; // 미리 저장해둠

        vec.push_back(i);
        // 폭발 문자열인지 확인
        if (curr==explode) {
            for (int j=0; j<explode.length(); j++){
                vec.pop_back();
            }
            
            // 폭발 이후 새롭게 참조할 curr
            if (vec.size()!=0) curr = arr[vec.back()];
            else curr="";
        }
    }

    if (vec.size()==0) cout << "FRULA";
    else {
        for (auto& i: vec){
            cout << str[i];
        }   
    }
    

   return 0;
}
