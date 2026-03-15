#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <climits>

using namespace std;

struct Coord {
    int x,y;
};
using p= pair<int,Coord>;

struct cmp{
    bool operator() (p& a, p&b){
        return a.first > b.first; // pq는 반대
    }
};

int dx[4] = {0,0,1,-1};
int dy[4]= {1,-1,0,0};

int test(int n){
    int arr[n+1][n+1];
    int path[n+1][n+1];
    fill(&path[0][0], &path[n][n]+1, INT_MAX);
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    // pq를 사용하면 더 효율적으로 돌 수 있음
    priority_queue<p, vector<p>, cmp> pq;
    pq.push({arr[0][0], {0,0}});

    while (!pq.empty()){
        auto [cost, coord] = pq.top(); pq.pop();

        if (path[coord.x][coord.y] < cost) continue;

        for (int d=0; d<4; d++){
            int newX= coord.x+dx[d];
            int newY= coord.y+dy[d];
            if (newX>=0 && newY>=0 && newX<n && newY<n){
                if (path[newX][newY] > cost + arr[newX][newY]){
                    // 최단 경로라면 갱신 후 넣어준다
                    path[newX][newY] = cost + arr[newX][newY];
                    pq.push({path[newX][newY], {newX, newY}});
                }
            }
        }
    }
    return path[n-1][n-1];
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);

    int i=1;
   while (true) {
        int N;
        cin >> N;

       if (N==0) break;
        
        cout << "Problem " << i++ << ": " << test(N) << endl;
    }

   return 0;
}
