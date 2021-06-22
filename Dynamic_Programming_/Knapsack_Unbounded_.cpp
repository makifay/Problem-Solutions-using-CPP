// Knapsack - Unbounded
// find maximum achievable value with a knapsack of weight W and multiple instances allowed.

// Time: O(W*n) like O(n^2)
// Space: O(W) likse O(n)

#include <bits/stdc++.h>
using namespace std;

int KnapsackUnbounded(int W, int n, int val[], int wt[])
{
    // best[i]: maximum values with knapsack capacity i.
    int best[W + 1];

    int counter = 0;
    memset(best, 0, sizeof best);

    for (int i = 0; i <= W; i++)
        for (int j = 0; j < n; j++)
            if (wt[j] <= i) // take new value and check
                best[i] = max(best[i],
                    val[j] + best[i - wt[j]]);

    return best[W];
}

// -----------------
int main()
{
    int W = 100;

    int wt[] = { 5, 10, 15 };
    int val[] = { 10, 30, 20 };

    int n = sizeof(val) / sizeof(val[0]); // item size

    cout << KnapsackUnbounded(W, n, val, wt);

    return 0;
}

