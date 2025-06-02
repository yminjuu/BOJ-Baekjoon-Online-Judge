#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    int sz= phone_book.size();
    sort(phone_book.begin(), phone_book.end());
    
    for (int i=0; i<sz-1; i++){
        size_t pos = phone_book[i+1].find(phone_book[i]);
        if (pos==0) return false;
    }

    return true;
}