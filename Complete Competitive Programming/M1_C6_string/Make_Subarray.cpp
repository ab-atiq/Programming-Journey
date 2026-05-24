/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/problems/MAKESUB

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int start_index = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                start_index = i;
                break;
            }
        }

        int end_index = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                end_index = i;
                break;
            }
        }

        // counting zeros between start_index and end_index
        int count_zero = 0;
        for (int i = start_index; i <= end_index; i++)
        {
            if (s[i] == '0')
            {
                count_zero++;
            }
        }
        cout << count_zero << endl;
    }
    return 0;
}

// one loop

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int first_1 = -1, last_1 = -1;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '1')
            {
                if (first_1 == -1)
                {
                    first_1 = i;
                }
                last_1 = i; // always update last_1
            }
        }

        int cnt_0 = 0; // count 0 between first_1 to last_1
        for (int i = first_1 + 1; i <= last_1 - 1; i++)
        {
            if (s[i] == '0')
            {
                cnt_0++;
            }
        }
        cout << cnt_0 << endl;
    }
    return 0;
}