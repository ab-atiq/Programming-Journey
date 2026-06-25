// problem link: https://www.hackerrank.com/contests/phitron-code-fest-2-b9/challenges/divisible-by-11-1-1-4/problem?isFullScreen=false

#include <iostream>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int odd_sum = 0, even_sum = 0;
    int len = str.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (i % 2 == 0) // problem statement 1 index base
        {
            odd_sum += str[i] - '0';
        }
        else
        {
            even_sum += str[i] - '0';
        }
    }
    int dif = odd_sum - even_sum;
    if (dif % 11 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}