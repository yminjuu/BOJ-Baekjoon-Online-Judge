#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
pair<int,int> rel[27];

// 전위 순회 (루트의 위치가 맨 앞)
void preOrder(char a){
    int index = a-'A';
    cout << a ;

    if (rel[index].first!='.') preOrder(rel[index].first);
    if (rel[index].second!='.') preOrder(rel[index].second);
}

// 중위 순회 (루트 위치 가운데)
void inOrder(char a){
    int index = a-'A';

    if (rel[index].first!='.') inOrder(rel[index].first);
    cout << a ;
    if (rel[index].second!='.') inOrder(rel[index].second);
}

// 후위 순회 (루트 위치 맨 끝)
void postOrder(char a){
    int index = a-'A';

    if (rel[index].first!='.') postOrder(rel[index].first);
    if (rel[index].second!='.') postOrder(rel[index].second);
    cout << a ;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   
   int N;
    cin >> N;
    
    for (int i=1; i<=N; i++){
        char curr, left, right;
        cin >> curr >> left >> right;
        rel[curr-'A']= make_pair(left, right);
    }

    preOrder('A');
    cout << "\n";

    inOrder('A');
    cout << "\n";

    postOrder('A');
    cout << "\n";

   return 0;
}
