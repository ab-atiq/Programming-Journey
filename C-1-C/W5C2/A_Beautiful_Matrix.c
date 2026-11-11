#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrix[6][6];
    // int row = 0, col = 0; // 0 index both are correct for this calculation
    int row = 1, col = 1; // 0 and 1 index both are correct for this calculation

    // Read the matrix.
    // if 0 index then i and j start from 0 and less than 5
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 1) // find the position of '1'
            {
                row = i;
                col = j;
            }
        }
    }

    // Calculate the number of moves needed
    // int moves = abs(row - 2) + abs(col - 2); // sum of the absolute differences between the current row and column indices and the target row and column indices
    int moves = abs(row - 3) + abs(col - 3); // sum of the absolute differences between the current row and column indices and the target row and column indices
    printf("%d\n", moves);

    return 0;
}

/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://codeforces.com/problemset/problem/263/A

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int mat[5][5];
    int r, c;
    int mid_i=2, mid_j=2;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == 1)
            {
                r = i;
                c = j;
            }
        }
    }
    // int move_x = abs(2 - r);
    // int move_y = abs(2 - c);
    int move_x = abs(mid_i - r);
    int move_y = abs(mid_j - c);
    printf("%d\n", move_x + move_y);
    return 0;
}