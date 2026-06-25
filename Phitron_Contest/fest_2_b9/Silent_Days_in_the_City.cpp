// problem link: https://www.hackerrank.com/contests/phitron-code-fest-2-b9/challenges/silent-days-in-the-city/problem?isFullScreen=false
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n + 1], pre[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    // prefix sum of silent day
    pre[1] = 0;
    for (int i = 2; i <= n - 1; i++)
    {

        pre[i] = pre[i - 1];
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
        {
            pre[i]++;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int cnt_silent = 0;
        int l, r;
        cin >> l >> r;
        if (l == 1)
        {
            l++;
        }
        if (r == n)
        {
            r--;
        }
        // general solution
        // for (int i = l; i <= r; i++)
        // {
        //     // cout<<arr[i-1]<<arr[i+1];
        //     if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
        //     {
        //         cnt_silent++;
        //     }
        // }
        // cout << cnt_silent << endl;

        // optimize solution
        cout << pre[r] - pre[l - 1] << endl;
    }

    return 0;
}