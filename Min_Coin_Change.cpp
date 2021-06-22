
// Minimum coin change in C++ - a dynamic programming

// N: sum, amount |  M: number of coins  
// Time: O(M*N)
// Space: O(N)

#include <bits/stdc++.h>
using namespace std;

int minCoins(int N, int M,  int coins[] )
{ 
    // N: sum , M: total_coins
   int maxVal = N + 1; 
   int dp [N+1] ;
   
  // Base case, min coins to make sum = 0 
  dp[0] = 0;
  
  // outer loop for possible values of sum between 1 to N
  for(int i = 1; i<=N; i++)
  {
    // initialize minimum number of coins needed to infinity
    dp[i] = maxVal;
    
    // Inner loop: index of each coin on array.
    for(int j = 0; j<M; j++) 
    { 
      if(coins[j] <= i)
      {
        // comparison whether solution include the new coin
        dp[i] = min( dp[i], 
                     1 + dp[i - coins[j]]  );
      }
    }
    
  }
  return dp[N];
}

// ---------- 
int main() {
  int sum = 50;
  int total_coins = 5;
  
  int coins[] = {1,2,4,6,8}; 
  
  cout << minCoins(sum, total_coins, coins);
}

