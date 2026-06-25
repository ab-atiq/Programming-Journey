// problem link: https://www.hackerrank.com/contests/phitron-code-fest-2-b9/challenges/big-name-phitron/problem?isFullScreen=false

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string sen;
    getline(cin, sen);
    int len = sen.length();
    // for (int i = 0; i < len; i++)
    // {
    //     if (sen[i] >= 'A' && sen[i] <= 'Z')
    //     {
    //         sen[i] = (char)(sen[i]) + 32;
    //     }
    // }
    // cout << sen << endl;
    stringstream ss(sen);
    string word;
    int cnt_phi = 0;
    while (ss >> word)
    {
        if (word == "phitron" || word == "PHITRON" || word == "Phitron")
        {
            cnt_phi++;
        }
    }
    cout << cnt_phi << endl;
    return 0;
}