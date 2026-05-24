/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/distinct-count/

// Time complexity: O(n log n) due to the insertion of elements into the set.
// Space complexity: O(n) in the worst case when all elements are distinct.
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int tc;
//     cin >> tc;
//     while (tc--)
//     {
//         int n, x;
//         cin >> n >> x;
//         set<int> s; // set is used to store distinct elements in sorted order
//         for (int i = 0; i < n; i++)
//         {
//             int a;
//             cin >> a;
//             s.insert(a);
//         }
//         // cout << s.size() << "\n";
//         if (s.size() < x)
//             cout << "Bad\n";
//         else if (s.size() == x)
//             cout << "Good\n";
//         else
//             cout << "Average\n";
//     }
//     return 0;
// }

// vector solution - using sort and unique to remove duplicates
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int tc;
//     cin >> tc;
//     while (tc--)
//     {
//         int n, x;
//         cin >> n >> x;
//         vector<int> v(n);
//         for (int i = 0; i < n; i++)
//         {
//             int a;
//             cin >> a;
//             v[i] = a;
//         }

//         // The vector solution has the same time complexity of O(n log n) due to sorting, and the space complexity is O(n) in the worst case when all elements are distinct.
//         sort(v.begin(), v.end());
//         v.erase(unique(v.begin(), v.end()), v.end()); // remove duplicates

//         // cout << v.size() << "\n";
//         if (v.size() < x)
//             cout << "Bad\n";
//         else if (v.size() == x)
//             cout << "Good\n";
//         else
//             cout << "Average\n";
//     }
//     return 0;
// }

// vector solution - count distinct elements
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int tc;
//     cin >> tc;
//     while (tc--)
//     {
//         int n, x;
//         cin >> n >> x;
//         vector<int> v(n);
//         for (int i = 0; i < n; i++)
//         {
//             int a;
//             cin >> a;
//             v[i] = a;
//         }
//         int distinct_count = 0;
//         sort(v.begin(), v.end()); // TC -> O(n log n)
//         for (int i = 0; i < n; i++)
//         {
//             if (i == 0 || v[i] != v[i - 1]) // count distinct elements
//                 distinct_count++;
//         }

//         // cout << distinct_count << "\n";
//         if (distinct_count < x)
//             cout << "Bad\n";
//         else if (distinct_count == x)
//             cout << "Good\n";
//         else
//             cout << "Average\n";
//     }
//     return 0;
// }

// solve using frequency array - not valid solution for 1<=A[i]<=10^9 getting TLE
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int tc;
//     cin >> tc;
//     while (tc--)
//     {
//         int n, x;
//         cin >> n >> x;
//         vector<int> fre(13000 + 1, 0); // frequency array to count occurrences of each element
//         for (int i = 0; i < n; i++)
//         {
//             int a;
//             cin >> a;
//             fre[a]++;
//         }
//         int distinct_count = 0;
//         for (int i = 0; i <= 13000; i++)
//         {
//             if (fre[i] > 0) // count distinct elements
//                 distinct_count++;
//         }

//         // cout << distinct_count << "\n";
//         if (distinct_count < x)
//             cout << "Bad\n";
//         else if (distinct_count == x)
//             cout << "Good\n";
//         else
//             cout << "Average\n";
//     }
//     return 0;
// }

// map solution - using map to count distinct elements
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, x;
        cin >> n >> x;
        map<int, int> freq; // map to count occurrences of each element
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            freq[a]++;
        }
        int distinct_count = freq.size(); // number of distinct elements is the size of the map

        // cout << distinct_count << "\n";
        if (distinct_count < x)
            cout << "Bad\n";
        else if (distinct_count == x)
            cout << "Good\n";
        else
            cout << "Average\n";
    }
    return 0;
}