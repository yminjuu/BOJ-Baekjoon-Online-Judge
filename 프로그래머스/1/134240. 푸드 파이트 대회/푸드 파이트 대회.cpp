#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string ansFront=""; 
    
    // 0 기준으로 앞 부분의 벡터를 완성한 뒤에 마지막에 넣는다
    for (int i=1; i< food.size(); i++){
        string newStr = string(food[i] / 2, '0'+i);
        
        ansFront+= newStr;
    }
    
    string ansBack = ansFront;
    reverse(ansBack.begin(), ansBack.end());
    return ansFront + "0" + ansBack;
}