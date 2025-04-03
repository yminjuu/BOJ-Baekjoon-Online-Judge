#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip> 

using namespace std;
int N;
typedef long double ld;
ld score;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
   priority_queue<ld, vector<ld> > pq; // 내림차순
   vector<ld> vec;

   cout << fixed << setprecision(3); 

   cin >> N;
   for (int i=0; i<7; i++) {cin >> score; pq.push(score);}
   N-=7;
   
   while (N--){
    cin >> score;
    if (pq.top() > score){
        pq.pop();
        pq.push(score);
    }
   }
   
   for (int i=0; i<7; i++) {vec.push_back(pq.top()); pq.pop();}

   for (int i=6; i>=0; i--) cout << vec[i] << endl;

   return 0;
}