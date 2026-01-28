#include <iostream>
#include <queue>
#include <string>
using namespace std;
string str;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;

    string substr = "";
    int sum = 0;
    int stat = 0; // +상태
    for (int i = 0; i < str.length(); i++)
    {
        if (stat)
        {
            if (str[i] == '-' || str[i] == '+')
            {
                sum -= stoi(substr);
                substr = "";
            }
            else
            {
                substr.append(str, i, 1);
            }
        }
        else
        {
            if (str[i] == '-')
            {
                sum += stoi(substr);
                substr = "";
                stat = 1;
            }
            else if (str[i] == '+')
            {
                sum += stoi(substr);
                substr = "";
            }
            else
            {
                substr.append(str, i, 1);
            }
        }
    }

    if (stat)
        sum -= stoi(substr);
    else
        sum += stoi(substr);
    cout << sum;
    return 0;
}