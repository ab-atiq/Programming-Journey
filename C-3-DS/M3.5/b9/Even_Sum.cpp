// problem link: https://www.codechef.com/problems/EVENSUM1
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
        int arr[n];
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        bool isEven = false;
        for (int i = 0; i < n; i++)
        {
            if ((sum - arr[i]) % 2 == 0)
            {
                isEven = true;
                break;
            }
        }
        if (isEven)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}