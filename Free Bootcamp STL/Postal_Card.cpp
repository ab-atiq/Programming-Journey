/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc287/tasks/abc287_b

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     vector<string> s(n), t(m);

//     for (int i = 0; i < n; i++)
//         cin >> s[i];
//     for (int i = 0; i < m; i++)
//         cin >> t[i];

//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             string last_three_s = s[i].substr(3, 3);
//             if (last_three_s == t[j])
//             {
//                 cnt++;
//                 break;
//             }
//         }
//     }
//     cout << cnt << "\n";
//     return 0;
// }

// solution using map - TC = O(n log m), SC = O(n + m)
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     vector<string> s(n);
//     map<string, int> t_map;

//     for (int i = 0; i < n; i++)
//         cin >> s[i];
//     for (int i = 0; i < m; i++)
//     {
//         string t;
//         cin >> t;
//         t_map[t]++;
//     }

//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         string last_three_s = s[i].substr(3, 3);
//         if (t_map.count(last_three_s))
//         {
//             // cnt += t_map[last_three_s]; // incorrect, becuase we only count for s string, not for number of t string
//             cnt++;
//         }
//     }
//     cout << cnt << "\n";
//     return 0;
// }


// solution using map - TC = O(n log m), SC = O(n + m)
// but we will consider intput as int
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    map<int, int> t_map;

    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        t_map[t]++;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int last_three_s = s[i] % 1000; // get the last three digits of s[i]
        if (t_map.count(last_three_s))
        {
            // cnt += t_map[last_three_s]; // incorrect, becuase we only count for s string, not for number of t string
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
