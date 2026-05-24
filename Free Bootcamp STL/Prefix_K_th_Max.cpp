/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc234/tasks/abc234_d

// my code
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    priority_queue<int, vector<int>, greater<int>> pq;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        pq.push(x);
        if (pq.size() == k)
        {
            cout << pq.top() << endl;
        }
        else if (pq.size() > k)
        {
            pq.pop();
            cout << pq.top() << endl;
        }
    }
    // for (int i = 0; i < k; i++)
    // {
    //     cout << pq.top() << endl;
    //     pq.pop();
    // }
    return 0;
}

// chatgpt
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; i++)
        cin >> P[i];

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N; i++)
    {
        minHeap.push(P[i]);
        if ((int)minHeap.size() > K)
            minHeap.pop();
        if (i + 1 >= K)
        {
            cout << minHeap.top() << "\n";
        }
    }
    return 0;
}
