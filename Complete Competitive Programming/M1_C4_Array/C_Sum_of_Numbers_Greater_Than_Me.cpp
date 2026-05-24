/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc331/tasks/abc331_c

// solution 1 - but gives TLE
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     for (int i = 0; i < n; i++)
//     {
//         long long int total_sum = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[j] > arr[i])
//             {
//                 total_sum += arr[j];
//             }
//         }
//         cout << total_sum << " ";
//     }
//     return 0;
// }

// solution 2 - optimal
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // Copy and sort
    vector<long long> sortedA = A;
    sort(sortedA.begin(), sortedA.end());

    // Build suffix sum array
    vector<long long> suf(N + 1, 0);
    for (int i = N - 1; i >= 0; i--)
    {
        suf[i] = suf[i + 1] + sortedA[i];
    }

    // For each A[i], find sum of numbers > A[i]
    vector<long long> ans(N);
    for (int i = 0; i < N; i++)
    {
        int idx = upper_bound(sortedA.begin(), sortedA.end(), A[i]) - sortedA.begin();
        ans[i] = suf[idx];
    }

    // Output
    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << (i + 1 < N ? ' ' : '\n');
    }

    return 0;
}
