#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int dp[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string s = "";
    int i = len1;
    int j = len2;

    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        }
        else {
            s += str1[i - 1];
            i--; j--;
        }
    }

    reverse(s.begin(), s.end());

    cout << dp[len1][len2] << "\n";
    if (dp[len1][len2] > 0) cout << s << "\n";

    return 0;
}