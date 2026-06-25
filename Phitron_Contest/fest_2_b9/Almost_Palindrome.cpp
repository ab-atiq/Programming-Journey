// problem link: https://www.hackerrank.com/contests/phitron-code-fest-2-b9/challenges/almost-palindrome-1-1/problem?isFullScreen=false

#include <iostream>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        int freq[26] = {0};
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            freq[str[i] - 'a']++;
        }
        int cnt = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % 2 == 1)
            {
                cnt += 1;
            }
        }
        if (cnt == 0)
        {
            cout << cnt << endl;
        }
        else
        {
            cout << cnt - 1 << endl;
        }
    }
    return 0;
}