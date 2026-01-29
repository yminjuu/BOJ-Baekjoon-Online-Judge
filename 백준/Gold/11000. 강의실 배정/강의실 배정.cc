#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef pair<int,int> Lecture;
priority_queue<Lecture, vector<Lecture>, greater<Lecture>> lectures; 
priority_queue<int, vector<int>, greater<int>> processing;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
   cin >> N;

    for (int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        lectures.push({a,b});
    }

    int rooms=1;
    processing.push(0);
    for (int i=0; i<N; i++){
        int start = lectures.top().first; int end= lectures.top().second;
        if (start<processing.top()){
            rooms++;
            processing.push(end);
        } else {
            processing.pop();
            processing.push(end);
        }
        lectures.pop();
    }

    cout << rooms;
   return 0;
}
