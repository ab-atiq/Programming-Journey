/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.codechef.com/START217D/problems/MAXADD

// getting TLE
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int T;
//     cin >> T;

//     while (T--)
//     {
//         int N;
//         long long M;
//         cin >> N >> M;

//         vector<long long> A(N), B(N);
//         for (int i = 0; i < N; i++)
//             cin >> A[i];
//         for (int i = 0; i < N; i++)
//             cin >> B[i];

//         // Prefix sum of B
//         vector<long long> prefB(N + 1, 0);
//         for (int i = 0; i < N; i++)
//         {
//             prefB[i + 1] = prefB[i] + B[i];
//         }

//         // Find critical K
//         long long K = 0;
//         for (int i = 0; i < N; i++)
//         {
//             K = max(K, A[i] - prefB[i]);
//         }
//         K = max(K, 1LL);

//         long long ans = 0;

//         // Part 1: X = 1 to min(M, K-1)
//         for (long long X = 1; X < K && X <= M; X++)
//         {
//             long long Y = X;
//             for (int i = 0; i < N; i++)
//             {
//                 Y = max(Y + B[i], A[i]);
//             }
//             ans += Y;
//         }

//         // Part 2: X = K to M
//         if (M >= K)
//         {
//             long long cnt = M - K + 1;
//             long long S = prefB[N];

//             // Sum of (X + S) from X = K to M
//             long long sumX = (K + M) * cnt / 2;
//             ans += sumX + cnt * S;
//         }

//         cout << ans << '\n';
//     }

//     return 0;
// }

// optimized - accepted
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        long long M;
        cin >> N >> M;

        vector<long long> A(N), B(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < N; i++)
            cin >> B[i];

        long long S = 0;
        for (int i = 0; i < N; i++)
            S += B[i];

        long long pref = 0;
        long long C = 0;
        for (int i = 0; i < N; i++)
        {
            pref += B[i];
            C = max(C, A[i] + (S - pref));
        }

        long long T0 = max(1LL, C - S);
        long long ans = 0;

        // X < T0
        long long cnt1 = min(M, T0 - 1);
        if (cnt1 > 0)
        {
            ans += cnt1 * C;
        }

        // X >= T0
        if (M >= T0)
        {
            long long cnt2 = M - T0 + 1;
            long long sumX = (T0 + M) * cnt2 / 2;
            ans += sumX + cnt2 * S;
        }

        cout << ans << '\n';
    }

    return 0;
}
