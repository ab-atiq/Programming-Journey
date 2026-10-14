/*
________________________
|                      |
|     AB Atiq          |
|______________________|
*/

// Problem link: https://codeforces.com/contest/1560/problem/A

// #include <stdio.h>
// int main()
// {
//     int tc;
//     scanf("%d", &tc);
//     while (tc--)
//     {
//         int k_th;
//         scanf("%d", &k_th);

//         int start = 0;
//         for (int i = 1; i <= k_th; i++)
//         {
//             start++;
//             // divisible by 3 or last digit 3
//             if (start % 3 == 0 && start % 10 == 3) // 33
//             {
//                 start++;
//             }
//             else if (start % 3 == 0) // 12
//             {
//                 start++;
//                 if (start % 10 == 3) // 13
//                     start++;
//             }
//             else if (start % 10 == 3) // 23
//             {
//                 start++;
//                 if (start % 3 == 0) // 24
//                     start++;
//             }
//         }
//         printf("%d\n", start);
//     }

//     return 0;
// }

// Solution using an array (Precomputation)

// #include <stdio.h>
// int main()
// {
//     int arr[1001]; // 1 index

//     int start = 0; // we can also mention "start" as "cur_num" or "number" for better understanding
//     for (int i = 1; i <= 1000; i++)
//     {
//         start++;
//         // divisible by 3 or last digit 3
//         if (start % 3 == 0 && start % 10 == 3) // 33
//         {
//             start++;
//         }
//         else if (start % 3 == 0) // 12
//         {
//             start++;
//             if (start % 10 == 3) // 13
//                 start++;
//         }
//         else if (start % 10 == 3) // 23
//         {
//             start++;
//             if (start % 3 == 0) // 24
//                 start++;
//         }
//         arr[i] = start;
//     }

//     int tc;
//     scanf("%d", &tc);
//     while (tc--)
//     {
//         int k_th;
//         scanf("%d", &k_th);

//         printf("%d\n", arr[k_th]);
//     }

//     return 0;
// }

// shorter version using your array precomputation approac

#include <stdio.h>

int main()
{
    int arr[1001]; // 1 index

    for (int num = 1, ind = 1; ind <= 1000; num++)
    {
        if (num % 3 != 0 && num % 10 != 3)
        {
            arr[ind] = num;
            ind++;
        }
    }

    int tc;
    scanf("%d", &tc);

    while (tc--)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", arr[k]);
    }

    return 0;
}

/*
For Codeforces A. Dislike of Threes, here are 5 different C solutions, from beginner-friendly to more efficient approaches.

First, one important correction in your solution: you used `&&` in the first condition, but a number should be skipped if it is divisible by `3` OR ends with digit `3`. Also, increasing `start` manually can skip valid numbers or count incorrectly.

The rule is simple:

- Skip numbers divisible by `3`.
- Skip numbers whose last digit is `3`.
- The first valid number is `1`.

## 1. Solution using `while` loop (Recommended for beginners)

```
#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int k;
        scanf("%d", &k);

        int num = 0, count = 0;

        while (count < k)
        {
            num++;

            if (num % 3 != 0 && num % 10 != 3)
            {
                count++;
            }
        }

        printf("%d\n", num);
    }

    return 0;
}
```

Logic: Increase `num` by one. If it satisfies both conditions, increase `count`. Stop when `count == k`.

## 2. Solution using `for` loop

```
#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int k, count = 0;
        scanf("%d", &k);

        for (int num = 1; ; num++)
        {
            if (num % 3 == 0 || num % 10 == 3)
                continue;

            count++;

            if (count == k)
            {
                printf("%d\n", num);
                break;
            }
        }
    }

    return 0;
}
```

Logic: Use `continue` to skip disliked numbers. When the counter reaches `k`, print the current number and stop the loop.

## 3. Solution using an array (Precomputation)

This approach calculates the first 1000 valid numbers once and stores them in an array.

```
#include <stdio.h>

int main()
{
    int arr[1001];
    int count = 0;

    for (int num = 1; count < 1000; num++)
    {
        if (num % 3 != 0 && num % 10 != 3)
        {
            arr[++count] = num;
        }
    }

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int k;
        scanf("%d", &k);

        printf("%d\n", arr[k]);
    }

    return 0;
}
```

Logic: Precompute the answers, then retrieve each answer directly using `arr[k]`.

Advantage: Each test case takes \\(O(1)\\) time after precomputation.

## 4. Solution using a separate function

This approach separates the logic into a function, making the code easier to reuse.

```
#include <stdio.h>

int findKth(int k)
{
    int num = 0;
    int count = 0;

    while (count < k)
    {
        num++;

        if (num % 3 != 0 && num % 10 != 3)
        {
            count++;
        }
    }

    return num;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int k;
        scanf("%d", &k);

        printf("%d\n", findKth(k));
    }

    return 0;
}
```

Logic: `findKth(k)` calculates and returns the \\(k\\)-th valid number. The `main()` function handles input and output.

## 5. Solution using recursion

This version uses recursion instead of a loop to find the answer.

```
#include <stdio.h>

int findKth(int num, int count, int k)
{
    if (count == k)
        return num;

    num++;

    if (num % 3 != 0 && num % 10 != 3)
        count++;

    return findKth(num, count, k);
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int k;
        scanf("%d", &k);

        printf("%d\n", findKth(0, 0, k));
    }

    return 0;
}
```

Logic: Each recursive call checks the next number and updates the valid-number counter until it reaches `k`.

Note: Recursion is useful for practicing the concept, but the loop-based solutions are preferable here.

## Compare the 5 approaches

| Approach | Main concept         | Recommendation               |
| -------- | -------------------- | ---------------------------- |
| 1        | `while` + counter    | Best for beginners           |
| 2        | `for` + `continue`   | Good for loop practice       |
| 3        | Array precomputation | Best for multiple test cases |
| 4        | Separate function    | Best for code organization   |
| 5        | Recursion            | Good for recursion practice  |

My recommendation: Start with Solution 1. It follows the problem statement directly, is easy to understand, and is efficient enough for the constraints of this problem.


*/