/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc368/tasks/abc368_a

// solution-1: basic idea: copy last k elements to new array first, then copy first n-k elements
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     int rotatedArr[n];

//     // first copy last k elements
//     int idx = 0;
//     for (int i = (n - k); i < n; i++)
//     {
//         rotatedArr[idx] = arr[i];
//         idx++;
//     }
//     // then copy first n-k elements
//     for (int i = 0; i < (n - k); i++)
//     {
//         rotatedArr[idx] = arr[i];
//         idx++;
//     }

//     // print rotated array
//     for (int i = 0; i < n; i++)
//     {
//         cout << rotatedArr[i] << " ";
//     }
//     return 0;
// }

// not store just print directly
// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     int A[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> A[i];
//     }

//     for (int i = n - k; i < n; i++)
//     {
//         cout << A[i] << " ";
//     }
//     for (int i = 0; i < n - k; i++)
//     {
//         cout << A[i];
//         // to avoid extra space at the end
//         if (i != n - k - 1)
//             cout << " ";
//     }
//     cout << endl;

//     return 0;
// }

// solution-2: (k times rotate to right using loop)
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     // rotate k times to right (TC: O(n*k))
//     for (int i = 0; i < k; i++)
//     {
//         int lastElement = arr[n - 1];
//         // shift all elements to right by 1
//         for (int j = n - 1; j > 0; j--)
//         {
//             arr[j] = arr[j - 1];
//         }
//         arr[0] = lastElement;
//     }

//     // print rotated array
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// solution-3: optimal approach: k times rotate to right using loop
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     // optimal approach: rotate k times to right (TC: O(n), SC: O(n))
//     int rotatedArr[n];
//     // k = k % n; // in case k > n (not needed in this problem as per constraints)
//     for (int i = 0; i < n; i++)
//     {
//         rotatedArr[(i + k) % n] = arr[i];
//     }

//     // print rotated array
//     for (int i = 0; i < n; i++)
//     {
//         cout << rotatedArr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// solution-4: using STL rotate function
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // rotate k times to left
    // k = k % n; // in case k > n
    // rotate(arr, arr + k, arr + n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    
    // rotate k times to right
    k = k % n; // in case k > n
    rotate(arr, arr + (n - k), arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
