#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> mp;
    
    for (int i=0; i<participant.size(); i++){
        mp[participant[i]]++;
    }
    
    for (int i=0; i<completion.size(); i++){
        mp[completion[i]]--;
    }
    
    for (auto itr: mp){
        if (itr.second!=0) {
            answer = itr.first;
            break;
        }}
    
    
    return answer;
}