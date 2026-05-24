/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://cses.fi/problemset/task/1083

// solution using vector and sorting - 2 test case failed
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     sort(arr.begin(), arr.end());
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] != i)
//         {
//             // cout << i << "->" << arr[i] << endl;
//             cout << i << endl;
//             break;
//         }
//     }

//     return 0;
// }

// solution using array and sorting - accepted
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int total_input = n - 1;
//     int arr[total_input + 1];
//     arr[total_input] = INT_MAX; // to avoid garbage value
//     for (int i = 0; i < total_input; i++)
//     {
//         cin >> arr[i];
//     }
//     sort(arr, arr + total_input + 1);
//     for (int i = 0; i < total_input + 1; i++)
//     {
//         if (arr[i] != i + 1)
//         {
//             // cout << i+1 << "->" << arr[i] << endl;
//             cout << i + 1 << endl;
//             break;
//         }
//     }

//     return 0;
// }
// rewrite solution using array and sorting - accepted
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    arr[n - 1] = INT_MAX; // to avoid garbage value
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for (int i = 1; i <= n; i++)
    {
        if (arr[i - 1] != i)
        {
            // cout << i << "->" << arr[i - 1] << endl;
            cout << i << endl;
            break;
        }
    }

    return 0;
}

// unique idea - sum of 1 to n natural numbers - sum of given numbers(n-1 numbers)
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int total_sum = (n * (n + 1)) / 2;
    long long int given_sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        given_sum += x;
    }
    cout << total_sum - given_sum << endl;
    return 0;
}

// cps - frequency array solution
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);

    int arr[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }

    int F[n + 1];
    for (int i = 1; i <= n; i++)
    {
        F[i] = 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        F[arr[i]]++;
    }

    int ans;

    for (int i = 1; i <= n; i++)
    {
        if (F[i] == 0)
        {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}

// cps - class (number present/absent) solution
#include <stdio.h>
int present[200001];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        scanf("%d", &x);
        present[x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (present[i] == 0)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}