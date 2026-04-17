#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    int N= players.size();
    
    string arr[N+2]; // 순서 -> 사람 이름
    map<string,int> mp; // 사람 이름 -> 순서
    for (int i=0; i<N; i++){
        string str = players[i];
        arr[i+1]= str;
        mp[str]= i+1; // 초기 순서 저장
    }
    
    for (int i=0; i<callings.size(); i++){
        string str = callings[i];
        // 앞뒤 모두
        int idx = mp[str]; // 앞지른 사람의 순서
        string behindName = arr[idx-1]; // 앞질러진 사람의 이름
        string frontName = arr[idx]; // 앞지른 사람의 이름
        
        // 배열에 반영
        arr[idx-1]= frontName;
        arr[idx]= behindName;
        // map에 반영
        mp[frontName]= idx-1;
        mp[behindName]= idx;
    }

    vector<string> answer;
    for (int i=1; i<=N; i++){
        answer.push_back(arr[i]);
    }
    return answer;
}