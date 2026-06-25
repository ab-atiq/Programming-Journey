// problem link: https://www.codechef.com/problems/EARLYWIN
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        string n1, n2;
        cin >> n1 >> n2;

        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (n1[i] == n2[j])
            {
                cout << n1[i];
            }
            else
            {
                break;
            }
            i++;
            j++;
        }
        cout << endl;
    }
    return 0;
}