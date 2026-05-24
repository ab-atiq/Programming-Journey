/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://atcoder.jp/contests/abc332/tasks/abc332_b

#include <stdio.h>
int main()
{
    int operations, glass_capacity, mug_capacity;
    scanf("%d %d %d", &operations, &glass_capacity, &mug_capacity);
    int current_glass = 0, current_mug = 0;
    for (int i = 0; i < operations; i++)
    {
        if (current_glass == glass_capacity)
        {
            current_glass = 0;
        }
        else if (current_mug == 0)
        {
            current_mug = mug_capacity;
        }
        else
        {
            int needed = glass_capacity - current_glass; // glass empty space
            if (needed > current_mug)
            {
                // mug has less water than needed
                current_glass += current_mug; // fill the glass with all the mug water
                current_mug = 0;              // mug becomes empty
            }
            else
            {
                // mug has enough water to fill the glass
                current_glass = glass_capacity; // glass becomes full
                current_mug -= needed;          // reduce the mug water by the needed amount
            }
        }
    }
    printf("%d %d\n", current_glass, current_mug);
    return 0;
}

// // chatgpt
#include <stdio.h>
int main()
{
    int k, g, m;
    scanf("%d %d %d", &k, &g, &m);
    int glass = 0, mug = 0;
    for (int i = 0; i < k; i++)
    {
        if (glass == g)
        {
            glass = 0;
        }
        else if (mug == 0)
        {
            mug = m;
        }
        else
        {
            int fill = g - glass;
            if (fill > mug)
            {
                glass += mug;
                mug = 0;
            }
            else
            {
                glass = g;
                mug -= fill;
            }
        }
    }
    printf("%d %d\n", glass, mug);
    return 0;
}

// // cps
// #include <stdio.h>

// int main()
// {
//     int k, g, m;
//     scanf("%d %d %d", &k, &g, &m);

//     int x = 0;
//     int y = 0;

//     for (int i = 1; i <= k; i++)
//     {
//         if (x == g)
//         {
//             x = 0;
//         }
//         else if (y == 0)
//         {
//             y = m;
//         }
//         else
//         {
//             int empty = g - x;
//             if (empty >= y)
//             {
//                 x += y;
//                 y = 0;
//             }
//             else
//             {
//                 y -= empty;
//                 x = g;
//             }
//         }
//     }

//     printf("%d %d\n", x, y);

//     return 0;
// }