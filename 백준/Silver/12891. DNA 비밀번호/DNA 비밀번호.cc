#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int S, P, tmp, ans=0;
string dna;
char ch;
map<char, int> basis; // 기준
map<char, int> mp; // 알파벳 개수 카운팅
map<char, bool> con; // 가능 여부를 기록

// 슬라이딩 윈도우 사용
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> S >> P;
    cin >> dna;

    char str[4] = {'A', 'C', 'G', 'T'};

    for (int i=0; i<4; i++){
        cin >> tmp;
        basis[str[i]]= tmp;
        mp[str[i]]= 0;
    }

    for (int i=0; i<P; i++){
        mp[dna.at(i)]++; // 0 초기화 후 1 증가
    }

    for (int i=0; i<4; i++){
        con[str[i]] = (mp[str[i]]>= basis[str[i]] ? true : false);
    }

    if (con['A'] && con['C'] && con['G'] && con['T']) ans++;

    int i=0; // 초기 시작점
    int j=P-1; // 초기 끝점

    while (j!=S-1){
        ch= dna.at(i++);
        mp[ch]--;
        con[ch]= (mp[ch]>=basis[ch] ? true : false);

        ch = dna.at(++j);
        mp[ch]++;
        con[ch]= (mp[ch]>=basis[ch] ? true : false);

        if (con['A'] && con['C'] && con['G'] && con['T']) ans++;
    }

    cout << ans;
}