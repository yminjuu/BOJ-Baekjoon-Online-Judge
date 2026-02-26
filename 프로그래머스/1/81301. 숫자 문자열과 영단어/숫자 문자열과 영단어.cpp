#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    int answer = 0;
        
    map<string, int> mp;
    mp.insert({"zero", 0});
    mp.insert({"one", 1});
    mp.insert({"two", 2});
    mp.insert({"three", 3});
    mp.insert({"four", 4});
    mp.insert({"five", 5});
    mp.insert({"six", 6});
    mp.insert({"seven", 7});
    mp.insert({"eight", 8});
    mp.insert({"nine", 9});
    
    string tmp="";
    for (int i=0; i<s.length(); i++){
        char c = s.at(i);
        if (c >= 'a' && c<='z') {
            tmp= tmp+c;
            if (mp.find(tmp)!=mp.end()){
                answer = answer*10 + mp[tmp];
                tmp= "";
            }
        }
        else {
            int value = mp[tmp];
            
            if (tmp!="")
                answer = answer*10  + value; // 이전의 string을 숫자로 변환 후
            answer = answer*10 + (c-'0');
            tmp=""; // tmp 초기화
        }
    }
    
    if (tmp!="") {
        int value = mp[tmp];
        answer = answer*10 + value;
    }
    
    return answer;
}