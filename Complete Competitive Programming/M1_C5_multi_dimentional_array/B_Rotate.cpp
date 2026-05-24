/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc309/tasks/abc309_b

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        cin.ignore(); // To ignore the newline character after each row input
    }
    // print original array
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }
    // Shift the integers written on the outer squares clockwise by one square each, and print the resulting grid.
    char temp = arr[0][n - 1]; // Store the top-right corner element
    // Move top row right
    for (int j = n - 1; j > 0; j--)
    {
        arr[0][j] = arr[0][j - 1];
    }
    char temp2 = arr[n - 1][n - 1]; // Store the bottom-right corner element
    // Move right column down
    for (int i = n - 1; i > 0; i--)
    {
        arr[i][n - 1] = arr[i - 1][n - 1];
    }
    arr[1][n - 1] = temp; // Place the stored top-right corner element into 2nd row of right column

    char temp3 = arr[n - 1][0]; // Store the bottom-left corner element
    // Move bottom row left
    for (int j = 0; j < n - 1; j++)
    {
        arr[n - 1][j] = arr[n - 1][j + 1];
    }
    arr[n - 1][n - 2] = temp2; // Place the stored bottom-right corner element into 2nd last column of bottom row

    // Move left column up
    for (int i = 0; i < n - 1; i++)
    {
        arr[i][0] = arr[i + 1][0];
    }
    arr[n - 2][0] = temp3; // Place the stored bottom-left corner element into 2nd last row of left column

    // Print the modified array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}

// cps
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);

    char A[n][n], NA[n][n];
    char temp;

    scanf("%c", &temp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &A[i][j]);
        }
        scanf("%c", &temp);
    }

    for (int j = 0; j <= n - 2; j++)
    {
        NA[0][j + 1] = A[0][j];
    }

    for (int i = 0; i <= n - 2; i++)
    {
        NA[i + 1][n - 1] = A[i][n - 1];
    }

    for (int j = 1; j <= n - 1; j++)
    {
        NA[n - 1][j - 1] = A[n - 1][j];
    }

    for (int i = 1; i <= n - 1; i++)
    {
        NA[i - 1][0] = A[i][0];
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            NA[i][j] = A[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", NA[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// chatgpt
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++)
        {
            A[i][j] = row[j] - '0';
        }
    }

    vector<int> ring;

    for (int j = 0; j < N; j++)
        ring.push_back(A[0][j]);

    for (int i = 1; i < N; i++)
        ring.push_back(A[i][N - 1]);

    for (int j = N - 2; j >= 0; j--)
        ring.push_back(A[N - 1][j]);

    for (int i = N - 2; i > 0; i--)
        ring.push_back(A[i][0]);

    int last = ring.back();
    ring.pop_back();
    ring.insert(ring.begin(), last);

    int idx = 0;

    for (int j = 0; j < N; j++)
        A[0][j] = ring[idx++];

    for (int i = 1; i < N; i++)
        A[i][N - 1] = ring[idx++];

    for (int j = N - 2; j >= 0; j--)
        A[N - 1][j] = ring[idx++];

    for (int i = N - 2; i > 0; i--)
        A[i][0] = ring[idx++];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << A[i][j];
        }
        cout << "\n";
    }

    return 0;
}
