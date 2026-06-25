#include <bits/stdc++.h>
using namespace std;

// void NewArray(vector<int> a, vector<int> b, vector<int> c, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         // c[i] = b[i];
//         c.push_back(b[i]);
//     }
//     int idx = n;
//     for (int i = 0; i < n; i++)
//     {
//         // c[idx++] = a[i];
//         c.push_back(a[i]);
//     }

//     for (int i = 0; i < n + n; i++)
//     {
//         cout << c[i] << " ";
//     }
// }

void NewArray(vector<int> a, vector<int> b, int n)
{
    vector<int> d;
    for (int i = 0; i < n; i++)
    {
        // c[i] = b[i];
        d.push_back(b[i]);
    }
    int idx = n;
    for (int i = 0; i < n; i++)
    {
        // c[idx++] = a[i];
        d.push_back(a[i]);
    }

    for (int i = 0; i < n + n; i++)
    {
        cout << d[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    // method 1: just print
    // for (int i = 0; i < n; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " ";
    // }

    // method 2: copy in c vector
    vector<int> c(n + n);
    // for (int i = 0; i < n; i++)
    // {
    //     c[i] = b[i];
    // }
    // int idx = n;
    // for (int i = 0; i < n; i++)
    // {
    //     c[idx++] = a[i];
    // }

    // for (int i = 0; i < n + n; i++)
    // {
    //     cout << c[i] << " ";
    // }

    // method 3: using function
    // NewArray(a, b, c, n);
    NewArray(a, b, n);

    return 0;
}




/* 
#include <iostream>
#include <vector>
#include <algorithm> // for copy
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N), C;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    // insert vector B then A in C vector - type 1
    // C.insert(C.end(), B.begin(), B.end());
    // C.insert(C.end(), A.begin(), A.end());

    // insert vector B then A in C vector - type 2
    // for (int i = 0; i < N; i++)
    // {
    //     C.push_back(B[i]);
    // }
    // for (int i = 0; i < N; i++)
    // {
    //     C.push_back(A[i]);
    // }

    // insert vector B then A in C vector - type 3
    // vector<int> C(N + N);
    // for (int i = 0; i < N; i++)
    // {
    //     C[i] = B[i];
    // }
    // for (int i = 0; i < N; i++)
    // {
    //     C[N + i] = A[i];
    // }

    // insert B then A in C vector - type 4 ('algorithm' header)
    copy(B.begin(), B.end(), back_inserter(C));
    copy(A.begin(), A.end(), back_inserter(C));

    // print vector C
    // for (int i = 0; i < N + N; i++)
    // {
    //     cout << C[i] << " ";
    // }
    // cout << endl;

    // print vector C
    for (auto element : C)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}

*/