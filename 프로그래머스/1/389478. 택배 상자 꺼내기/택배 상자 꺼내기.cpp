#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
int nums[105][105];

int solution(int n, int w, int num) {
    int answer = 0;
   
    int myColumn, myRow;
    for (int i=1; i<=n; i++){
        int row = (i-1) / w;
        
        int column;
        if (row%2==0){
            // 정방향
            column = (i-1) % w;
        } else {
            // 역방향
            column = (w-1) - (i-1) % w;
        }
        
        if (i==num){ myColumn= column; myRow= row;}
        nums[row][column]= i;
    }
    
    int tmp=myRow;
    while (true){
        cout << nums[tmp][myColumn] << endl;
        if (nums[tmp++][myColumn]!=0) answer++;
        else break;
    }
    
    return answer;
}