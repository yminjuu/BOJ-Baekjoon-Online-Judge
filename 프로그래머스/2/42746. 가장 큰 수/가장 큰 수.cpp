#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 3 30
// 30 3
// 3이 더 커야 한다
// 330 303
// 303이 더 크다고 판단해야 한다.
bool compare(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> vec;
    for (int i=0; i<numbers.size(); i++){
        vec.push_back(to_string(numbers[i]));
    }
    
    // begin과 end다!!
    sort(vec.begin(), vec.end(), compare);
    
    for (int i=0; i<numbers.size(); i++){
        answer+=vec[i];
    }
    
    if (answer.at(0)=='0') return "0";
    
    return answer;
}
