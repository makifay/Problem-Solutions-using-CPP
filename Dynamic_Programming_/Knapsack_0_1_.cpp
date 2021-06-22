// 0-1 Knapsack problem
// A Dynamic Programming based solution

/* >> Complexity Analysis: 
	- Time Complexity: O(N*W) 
	where ‘N’ is the number of weight element and ‘W’ is capacity. 

	- Auxiliary Space: O(N*W)
	The use of 2-D array of size ‘N*W’. 
*/

#include <stdio.h>
#include <vector>
#include <iostream>

// A utility function returning maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// returns the max value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) // iteration over row
    {
        for (w = 0; w <= W; w++) // iteration over column
        {

            if (i == 0 || w == 0)
                K[i][w] = 0; // fill zero the first row and columns
            else if (wt[i - 1] <= w) // take the new value and check
                K[i][w] = max(K[i - 1][w],
                    K[i - 1][w - wt[i - 1]] + val[i - 1]);
            else
                K[i][w] = K[i - 1][w]; // if value is at the left, take that value
        }
    }

    return K[n][W];
}


// ---------------
int main()
{
    // Test 1
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    std::cout << "Test-1:" << std::endl;
    printf("%d \n", knapSack(W, wt, val, n));

    // Test 2
    int val2[] = { 1, 4, 8, 5 };
    int wt2[] = { 3, 3, 5, 6 };
    W = 10;
    n = sizeof(val2) / sizeof(val2[0]);
    std::cout << std::endl
              << "Test-2:" << std::endl;
    printf("%d \n", knapSack(W, wt2, val2, n));

    // Test 3
    int val3[] = { 2, 2, 4, 5, 3 };
    int wt3[] = { 3, 1, 3, 4, 2 };
    W = 7;
    n = sizeof(val3) / sizeof(val3[0]);
    std::cout << std::endl
              << "Test-3:" << std::endl;
    printf("%d \n", knapSack(W, wt3, val3, n));

    return 0;
}

