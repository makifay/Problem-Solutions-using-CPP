// Subset Sum Problem
// Check if there is any subset which sum of the items will be equal to the given number

// Dynamic Programming Approach

// Time: O(n x sum)
// Space: O(n x sum)

#include <iostream>
#include <vector>

// Return true if there exists a subset
bool SubsetSum(std::vector<int>& arr, int sum)
{
    int n = arr.size();

    // T[i][j] : memoization table
    // stores true if  there is a subset ( sum of first i items)
    bool T[n + 1][sum + 1];

    // no items in the list and sum is non-zero
    for (int j = 1; j <= sum; j++)
        T[0][j] = false;

    // if sum is zero
    for (int i = 0; i <= n; i++)
        T[i][0] = true;

    for (int i = 1; i <= n; i++) {
        // iterate all sum from 1 to sum
        for (int j = 1; j <= sum; j++) {
            // exclude ith element if j-arr[i-1] is negative
            if (arr[i - 1] > j)
                T[i][j] = T[i - 1][j];
            else // find subset with sum j by checking the ith item
                T[i][j] = T[i - 1][j] || T[i - 1][j - arr[i - 1]];
        }
    }

    return T[n][sum];
}

// -------------
int main()
{
    std::vector<int> arr1 = { 7, 3, 2, 5, 8 };
    int sum = 18;
    std::cout << "Test-1: " << SubsetSum(arr1, sum) << std::endl;

    std::vector<int> arr2 = { 3, 34, 4, 12, 5, 2 };
    sum = 9;
    std::cout << "Test-2: " << SubsetSum(arr2, sum) << std::endl;

    std::vector<int> arr3 = { 2, 4, 6, 8, 10 };
    sum = 15;
    std::cout << "Test-3: " << SubsetSum(arr3, sum) << std::endl;

    return 0;
}

