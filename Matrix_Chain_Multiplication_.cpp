// Most Optimized Matrix Order for Matrix-Chain Multiplication

// Algorithm ref: http://www.cs.bilkent.edu.tr/~atat/473/lecture10.pdf

// Time Complexity: O(n^3), 3 nested loops
// Auxiliary Space: O(n^2)

#include <bits/stdc++.h>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
int MatrixChain(int p[], int n)
{

    /*  one extra row and one extra column are allocated in m[][]. 
	    0th row and 0th column of m[][] are not used */
    int m[n][n];

    int i, j, k, L, q;

    // m[i, j] = Minimum number of scalar multiplications needed to compute

    // cost is 0 when multiplying one matrix.
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L is chain length.
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++) {
                // q = cost, scalar multiplications
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];

                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}


// -------------
int main()
{
    int arr[] = { 3, 5, 7, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is "
         << MatrixChain(arr, size);

    return 0;
}
