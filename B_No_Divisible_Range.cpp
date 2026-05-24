/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc435/tasks/abc435_b

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int cnt_not_divisible = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            // cout << i << " " << j << endl;
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            int flag = 0; // not divisible
            for (int k = i; k <= j; k++)
            {
                if(sum % arr[k] == 0){
                    flag = 1; // divisible
                    break;
                }
            }
            if(flag == 0){
                cnt_not_divisible++;
            }
        }
    }
    cout << cnt_not_divisible << endl;
    return 0;
}