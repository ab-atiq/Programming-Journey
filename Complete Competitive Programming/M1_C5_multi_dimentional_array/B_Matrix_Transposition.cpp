/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc237/tasks/abc237_b

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w;
    cin >> h >> w;
    int a[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }
    // Transpose and print the matrix - first column print then second column and so on.
    for (int j = 0; j < w; j++) // outer loop for column
    {
        for (int i = 0; i < h; i++) // inner loop for row
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    // solution 2 - store b[w][h]; // transpose matrix
    // int b[w][h];
    // for (int j = 0; j < w; j++)
    // {
    //     for (int i = 0; i < h; i++)
    //     {
    //         b[j][i] = a[i][j];
    //     }
    // }
    // // print the transpose matrix
    // for (int i = 0; i < w; i++)
    // {
    //     for (int j = 0; j < h; j++)
    //     {
    //         cout << b[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}

// cps
#include<stdio.h>

int main(){

    int h, w;
    scanf("%d%d",&h,&w);

    int arr[h][w];

    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            scanf("%d",&arr[i][j]);
        }
    }

    for(int j=0; j<w; j++){
        for(int i=0; i<h; i++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }


    return 0;
}