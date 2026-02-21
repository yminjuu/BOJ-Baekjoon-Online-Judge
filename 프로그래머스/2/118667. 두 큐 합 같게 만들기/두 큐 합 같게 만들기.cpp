#include <string>
#include <vector>
#include <queue>
#include <numeric>


using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    // 큐를 벡터로 바로 초기화할 수 잇는지
    queue<int> q1;
    queue<int> q2;
    
    // 전체 원소 합을 구하고
    long total=0;
    for (int i=0; i<queue1.size(); i++){ total+=queue1[i]; q1.push(queue1[i]);}
    for (int i=0; i<queue2.size(); i++) {total+=queue2[i]; q2.push(queue2[i]);}
    
    // 홀수면 바로 return 
    if (total%2==1) return -1;
    
    long total1 = accumulate(queue1.begin(), queue1.end(), 0);
    long total2 = accumulate(queue2.begin(), queue2.end(), 0);
    // 어차피 뺴는 건 앞에서부터 되고 넣는 건 뒤에만 가능함
    // 합이 작은 큐로 값이 가는 것을 반복한다.
    
    long cnt= 0; long base = q1.size()+q2.size();
    while (true){
        if (total1==total2) return cnt;
        if (base*3 <= cnt) return -1;
        
        cnt++; long tmp;
        if (total1 > total2){
            tmp = q1.front(); q1.pop();
            q2.push(tmp);
            total1-=tmp; total2+=tmp;
        } else {
            tmp = q2.front(); q2.pop();
            q1.push(tmp);
            total2-=tmp; total1+=tmp;
        }
    }
    return -1;
}