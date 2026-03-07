#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> mp;
    
    for (auto& v : clothes){
        mp[v[1]]++;
    }
    
    int total= 1;
    for (auto& [key, value]: mp) {
        total *= (value+1);
    }
    
    answer= total -1;
    
    return answer;
}