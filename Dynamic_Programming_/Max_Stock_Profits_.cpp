// Maximize Stock Profits by buying and selling

// Dynamic Programming Approach
// Adapting to the Knapsack Problem

#include <bits/stdc++.h>
using namespace std;

int Knapsack(std::vector<int>& vals, std::vector<int>& weights, int capacity)
{

    int n = weights.size();
    int K[n + 1][capacity + 1]; // memoization table

    // traverse every subset of items up to a given weight (capacity)
    for (int i = 0; i <= weights.size(); ++i) {

        for (int j = 0; j <= capacity; ++j) {

            if (i == 0 || j == 0) { //1st iteration start with 0
                K[i][j] = 0;
            }
            else if (weights[i - 1] <= j) { // check whether adding value is better
                K[i][j] = std::max(K[i - 1][j],
                    K[i - 1][j - weights[i - 1]] + vals[i - 1]);
            }
            else { // else take the old value
                K[i][j] = K[i - 1][j];
            }
        }
    }

    return K[weights.size()][capacity];
}

int MaxProfits(int savings, std::vector<int>& currVals, std::vector<int>& futureVals)
{

    //we have weights, values is required for adapting to the knapsack
    std::vector<int> values(currVals.size());

    for (int i = 0; i < currVals.size(); ++i) {
        // profit as value,  currVals as weight
        int actualVal = futureVals[i] - currVals[i];

        if (actualVal < 0) {
            actualVal = 0; //worst case would be 0, not negative
        }
        values[i] = actualVal;
    }

    return Knapsack(values, currVals, savings);
}

int main(void)
{

    int savings = 500;
    std::vector<int> currVals = { 150, 199, 200, 168, 153 };
    std::vector<int> futureVals = { 140, 175, 199, 121, 111 };
    std::cout << MaxProfits(savings, currVals, futureVals) << std::endl;

    savings = 30;
    currVals = { 1, 2, 4, 6 };
    futureVals = { 5, 3, 5, 6 };
    std::cout << MaxProfits(savings, currVals, futureVals) << std::endl;

    savings = 250;
    currVals = { 175, 133, 109, 201, 97 };
    futureVals = { 200, 125, 128, 228, 133 };
    std::cout << MaxProfits(savings, currVals, futureVals) << std::endl;

    return 0;
}
