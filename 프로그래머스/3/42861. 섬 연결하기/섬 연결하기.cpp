#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int parent[102];

int findFunc(int a){
    if (parent[a]==a) return a;
    
    return parent[a]= findFunc(parent[a]);
}

void unionFunc (int a, int b){
    int pA= findFunc(a);
    int pB= findFunc(b);
    
    if (pA!=pB) parent[pB]= pA; // 집합의 부모(루트)끼리 연결
}

bool cmp (const vector<int>& a, const vector<int>& b) {
       return a[2] < b[2]; // 작은 게 먼저
}

int solution(int n, vector<vector<int>> costs) {
    int ans=0;
    sort(costs.begin(), costs.end(), cmp);
    
    for (int i=0; i<n; i++){
        parent[i]= i;
    }
    
    for (int i=0; i<costs.size(); i++){
        // 비용이 적은 엣지부터 탐색
        int s = costs[i][0];
        int e = costs[i][1];
        int cost= costs[i][2];
        
        
        // 둘이 어느 집합에 포함되어 있는지 확인
        int pS= findFunc(s);
        int pE= findFunc(e);
        if (pS!=pE){
            // 아직 집합이 연결되지 않았다면
            unionFunc(pS, pE);
            ans+= cost;
        }
    }
    
    return ans;
}
