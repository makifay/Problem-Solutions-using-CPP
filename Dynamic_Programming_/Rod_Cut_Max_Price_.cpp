// Rod cutting problem
// Dynamic Programming solution

// Time: O(n^2)
// Space: O(n)

#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

// returns the max
int Max(int a, int b) { return (a > b) ? a : b; }

// returns the best attainable price
int cutRod(vector<int>& price, int n)
{
    int bestVals[n + 1];
    bestVals[0] = 0;
    int i, j;

    // Build the table val[] in bottom up manner
    for (i = 1; i <= n; i++) {
        int max_val = INT_MIN;

        // P:price , B: bestVals
        /* B(4) = max { P1 + B(3)
    	                P2 + B(2)
    	                P3 + B(1) 
    	                P4        }
    	*/

        // price[0]: 1.item, bestVals[1]: 1.item
        for (j = 0; j < i; j++)
            max_val = Max(max_val, price[j] + bestVals[i - j - 1]);

        bestVals[i] = max_val;
    }

    return bestVals[n];
}

// ------------------
int main()
{
    vector<int> arr = { 1, 5, 8, 9, 10, 17, 17, 20 };
    int size = arr.size();
    printf("Maximum Attainable Value is %d", cutRod(arr, size));
    getchar();

    return 0;
}
