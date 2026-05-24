/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/START217D/problems/MAKEAP7

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int tc;
//     cin >> tc;
//     while (tc--)
//     {
//         int n;
//         cin >> n;
//         int arr[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         int min_variance = INT_MAX;
//         for (int i = 1; i < n; i++)
//         {
//             int variance = arr[i] - arr[i - 1];
//             min_variance = min(min_variance, variance);
//         }
//         // total element needed
//         int total_element = (arr[n - 1] - arr[0]) / min_variance + 1;
//         // elements to be added
//         cout << total_element - n << endl;
//     }
//     return 0;
// }

// help from chatgpt - using gcd

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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // int min_variance = INT_MAX;
        int diff = 0;
        for (int i = 1; i < n; i++)
        {
            int variance = arr[i] - arr[i - 1];
            diff = __gcd(diff, variance);
        }
        // total element needed
        int total_element = (arr[n - 1] - arr[0]) / diff + 1;
        // elements to be added
        cout << total_element - n << endl;
    }
    return 0;
}