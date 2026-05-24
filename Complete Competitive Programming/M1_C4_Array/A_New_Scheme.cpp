/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc308/tasks/abc308_a

// solution using conditional statements
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int s1, s2, s3, s4, s5, s6, s7, s8;
//     cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8;
//     // non decreasing order check
//     if (s1 <= s2 && s2 <= s3 && s3 <= s4 && s4 <= s5 && s5 <= s6 && s6 <= s7 && s7 <= s8)
//     {
//         // all are multiples of 25 check
//         if (s1 % 25 == 0 && s2 % 25 == 0 && s3 % 25 == 0 && s4 % 25 == 0 && s5 % 25 == 0 && s6 % 25 == 0 && s7 % 25 == 0 && s8 % 25 == 0)
//         {
//             if (s1 >= 100 && s8 <= 675) // range check
//             {
//                 cout << "Yes\n";
//             }
//             else
//             {
//                 cout << "No\n";
//             }
//         }
//         else
//         {
//             cout << "No\n";
//         }
//     }
//     else
//     {
//         cout << "No\n";
//     }
//     return 0;
// }

// solution using array - simple(cps)
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int arr[8];
//     for (int i = 0; i < 8; i++)
//     {
//         cin >> arr[i];
//     }
//     bool isValid = true;

//     // non decreasing order check
//     for (int i = 0; i < 7; i++)
//     {
//         if (arr[i] > arr[i + 1])
//         {
//             isValid = false;
//             break;
//         }
//     }

//     // all are multiples of 25 check
//     for (int i = 0; i < 8; i++)
//     {
//         if (arr[i] % 25 != 0)
//         {
//             isValid = false;
//             break;
//         }
//     }

//     // range check
//     if (arr[0] < 100 || arr[7] > 675)
//     {
//         isValid = false;
//     }

//     if (isValid)
//     {
//         cout << "Yes\n";
//     }
//     else
//     {
//         cout << "No\n";
//     }

//     return 0;
// }

// solution using array - optimized
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[8];
    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
    }

    bool isValid = true; // assume valid
    for (int i = 0; i < 7; i++)
    {
        // non decreasing order check
        if (arr[i] > arr[i + 1])
        {

            isValid = false;
            // break;
        }
        // all are multiples of 25 check
        else if (arr[i] % 25 != 0 || arr[i + 1] % 25 != 0)
        {

            isValid = false;
            // break;
        }
        // range check
        else if (arr[i] < 100 || arr[i] > 675 || arr[i + 1] < 100 || arr[i + 1] > 675)
        {
            isValid = false;
            // break;
        }
    }

    if (isValid)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}