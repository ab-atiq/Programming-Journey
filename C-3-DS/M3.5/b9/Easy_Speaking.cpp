// problem link: https://www.codechef.com/problems/EZSPK

#include <iostream>
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
        int count = 0;
        bool is_hard = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                count = 0;
            }
            else
            {
                count++;
                if (count >= 4)
                {
                    is_hard = true;
                    break;
                }
            }
        }
        if (is_hard)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}