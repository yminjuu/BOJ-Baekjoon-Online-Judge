#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    set<int> mySet;
    
    for (int num : nums){
        mySet.insert(num);
    }
    
    
    return min(mySet.size(), nums.size()/2);
}