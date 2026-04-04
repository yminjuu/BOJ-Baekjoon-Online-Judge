#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>

// 시작시간, 종료시간을 (분) 단위 변환
struct Book {
    int start, end;
    bool operator < (const Book& tmp) const {
        return start > tmp.start; // pq는 반대
    }
    bool operator > (const Book& tmp) const {
        return start < tmp.start; // pq는 반대
    }
};

using namespace std;

// 15:00 형태
int toMinutes(string str){
    int hour = stoi(str.substr(0, 2));
    int min = stoi(str.substr(3,2));
    return hour*60+min;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    priority_queue<Book> bookings;
    priority_queue<int, vector<int>, greater<int>> rooms;
    
    for (int i=0; i< book_time.size(); i++){
        int startMinute = toMinutes(book_time[i][0]);
        int endMinute = toMinutes(book_time[i][1]);
        
        bookings.push({startMinute, endMinute});
    }
    
    rooms.push(0); answer++;
    while (!bookings.empty()){
        int startMinute = bookings.top().start;
        int endMinute = bookings.top().end;
        bookings.pop();
        
        if (rooms.top() <= startMinute) {
            // 바로 사용 가능
            rooms.pop();
            rooms.push(endMinute + 10);
        } else {
            // 새로 방을 만듦
            rooms.push(endMinute+10);
            answer++;
            } 
    }
    
    return answer;
}