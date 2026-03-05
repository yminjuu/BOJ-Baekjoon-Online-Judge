#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int isUsed[31];

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int cnt=0;
    // 모든 5가지 조합을 뽑기 위한 마스크 벡터 (0, 1로만 구성)
    vector<int> mask;
    
    for (int i=1; i<=5; i++){
        mask.push_back(0);
    }
    for (int i=6; i<=n; i++){
        mask.push_back(1);
    }
    
    do {
        for (int i=0; i<mask.size(); i++){
            if (mask[i]==0) {
                isUsed[i+1]= 1;
            }}
            
            bool istrue= true;
            // 모든 힌트에 대해 논리적으로 맞는지
            for (int j=0; j< q.size(); j++){
                int tmpAns=0;
                for (int k=0; k< q[j].size(); k++){
                    if (isUsed[q[j][k]]==1) {tmpAns++;}
                }
                if (tmpAns!=ans[j]){
                    istrue= false; 
                    break;
                }
            }
            
            if (istrue) cnt++;
            fill(&isUsed[0], &isUsed[30]+1, 0); // 초기화
        
    } while (next_permutation(mask.begin(), mask.end()));
    
    return cnt;
}