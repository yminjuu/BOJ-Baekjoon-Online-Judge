#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int N;

typedef struct Homework {
    string subject;
    int startMin, leftMin; // 시작시간과 남은 시간
} Homework;

bool compare(Homework& a, Homework& b) {
        return a.startMin < b.startMin;
}

vector<Homework> homeworks;

queue<Homework> q;
stack<Homework> stck;
vector<string> answer;

void doLeftHomework(int currTime, int nextTime){
    // nextTime까지 할 수 있는 만큼 stack에 쌓인 숙제를 한다.
    while (!stck.empty()){
        Homework curr = stck.top(); stck.pop();
        
        if (currTime + curr.leftMin <= nextTime){
            currTime += curr.leftMin;
            answer.push_back(curr.subject);
        } else {
            // 못 끝냄
            stck.push({curr.subject, 0, (currTime+curr.leftMin - nextTime)});
            break;
        }
    }
}

vector<string> solution(vector<vector<string>> plans) {
    N = plans.size();
    
    for (int i=0; i<N; i++){
        string firstTime = plans[i][1];
        int firstDelIdx= firstTime.find(":");
        string firstH = firstTime.substr(0, firstDelIdx);
        string firstM = firstTime.substr(firstDelIdx+1);
        int firstFullM = stoi(firstH)*60 + stoi(firstM);
        
        homeworks.push_back({plans[i][0], firstFullM, stoi(plans[i][2])});
    }
    
    sort(homeworks.begin(), homeworks.end(), compare);
    
    for (int i=0; i<N; i++){
        q.push(homeworks[i]);
    }
    
    while (!q.empty() || !stck.empty()){
        // 큐가 우선
        if (!q.empty()) {
            Homework curr = q.front();
            q.pop();
            bool isLast= q.empty();
            
            if (isLast || curr.startMin + curr.leftMin == q.front().startMin) {
                answer.push_back(curr.subject);
            } else if (curr.startMin + curr.leftMin < q.front().startMin) {
                int doneTime = curr.startMin + curr.leftMin;
                answer.push_back(curr.subject);
                
                doLeftHomework(doneTime, q.front().startMin);
            } else {
                stck.push({curr.subject, 0, (curr.startMin+curr.leftMin-q.front().startMin)});
            }
        } else {
            // 계속해서 stack에서 꺼내서 한다.
            doLeftHomework(0, 1600);
        }
    }
    
    //sort 필요
    return answer;
}