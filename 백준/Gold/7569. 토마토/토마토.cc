#include <iostream>
#include <queue>
#include <algorithm>

using namespace std; 

int M,N,H, tomato;
int box[102][102][102]; // 각각 높이 세로 가로
int total= 0;

queue<pair<pair<int, int>,int> > q;
queue<pair<pair<int, int>,int> > waitQ;

int ripe(int m, int n, int h){
    int tg=0;
    if (m+1<=H && box[m+1][n][h]==0) {
        box[m+1][n][h]=1;
        tg=1;
        waitQ.push(make_pair(make_pair(m+1,n), h));
    }
    if (m-1>0 && box[m-1][n][h]==0) {
        box[m-1][n][h]=1;
        tg=1;
        waitQ.push(make_pair(make_pair(m-1,n), h));
    }
    if (h-1>0 && box[m][n][h-1]==0) {
        box[m][n][h-1]=1;
        tg=1;
        waitQ.push(make_pair(make_pair(m,n), h-1));
    }
    if (h+1<=M && box[m][n][h+1]==0) {
        box[m][n][h+1]=1;
        tg=1;
        waitQ.push(make_pair(make_pair(m,n), h+1));
    }
    if (n-1>0 && box[m][n-1][h]==0) {
        box[m][n-1][h]=1;
        tg=1;
        waitQ.push(make_pair(make_pair(m,n-1), h));
    }
    if (n+1<=N && box[m][n+1][h]==0) {
        box[m][n+1][h]=1;
        tg=1;
        waitQ.push(make_pair(make_pair(m,n+1), h));
    }
    box[m][n][h]++;
    return tg;
}

void BFS(){
    while (true){
        int change = 0 ;
        if (waitQ.size()==0) return;
        swap(q, waitQ);
        while (!q.empty()){
            change==0 ? change= ripe(q.front().first.first, q.front().first.second, q.front().second) : ripe(q.front().first.first, q.front().first.second, q.front().second);
            q.pop();
        }
        if (change==1) {
            total++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> M >> N >> H; // 각각 가로, 세로, 높이

    for (int i=1; i<=H; i++){ 
        for (int j=1; j<=N; j++){ 
            for (int k=1; k<=M; k++){ 
                cin >> box[i][j][k];
                if (box[i][j][k]==1) waitQ.push(make_pair(make_pair(i,j), k));
            }
        }
    }

    BFS();

    for (int i=1; i<=H; i++){
        for (int j=1; j<=N; j++){ 
            for (int k=1; k<=M; k++){
                if (box[i][j][k]==0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << total;
    return 0;
}