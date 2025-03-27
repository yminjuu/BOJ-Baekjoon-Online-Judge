#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<int> stck;
    
    // stack을 활용한다.
    for (int i=0; i< s.length(); i++){
        if (s.at(i)==')' && !stck.empty() && stck.top()=='(')
            stck.pop();
        else {
            stck.push(s.at(i));
        }
        // stck에 넣는다.
        // 만약 top이 ( 이고 들어갈 문자가 )이면 pop 하고 다음으로 넘어간다.
    }
    answer = stck.empty();

    return answer;
}