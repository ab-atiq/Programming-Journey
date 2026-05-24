/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc286/tasks/abc286_a

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n, p, q, r, s;
//     cin >> n >> p >> q >> r >> s;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     int temp[q - p + 1];
//     // p to q value store in temp
//     for (int i = p - 1, j = 0; i < q; i++, j++) // 0 indexed
//     {
//         temp[j] = arr[i];
//     }
//     // r to s value store in p to q
//     for (int i = r - 1, j = p - 1; i < s; i++, j++) // 0 indexed
//     {
//         arr[j] = arr[i];
//     }
//     // temp value store in r to s
//     for (int i = 0, j = r - 1; i < (q - p + 1); i++, j++) // 0 indexed
//     {
//         arr[j] = temp[i];
//     }
//     // print the array
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

// just print - my version + cps
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, p, q, r, s;
    cin >> n >> p >> q >> r >> s;
    int arr[n + 1]; // 1 indexed

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    // print 1 to before p
    for (int i = 1; i < p; i++)
    {
        cout << arr[i] << " ";
    }
    // print r to s
    for (int i = r; i <= s; i++)
    {
        cout << arr[i] << " ";
    }
    // print from after q to before r
    for (int i = q + 1; i < r; i++)
    {
        cout << arr[i] << " ";
    }
    // print p to q
    for (int i = p; i <= q; i++)
    {
        cout << arr[i] << " ";
    }
    // print from after s to n
    for (int i = s + 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}