// class Solution {
// public:
//     int solve(vector<vector<int>>& coins, int i, int j, int rem, int n, int m,
//               vector<vector<vector<int>>>& dp) {
  

//         if (i == n - 1 && j == m - 1) {
//             if (coins[i][j] >= 0) {
//                 return coins[i][j];
//             } else {
                
//        return (rem > 0) ? 0 : coins[i][j];

//             }
//         }
       
//         if (i >= n || j >= m)
//             return -1e9;

//         if (dp[i][j][rem] != -1) //**
//             return dp[i][j][rem];

//         int right = -1e9, down = -1e9;

//         if (coins[i][j] >= 0) {
//             right =
//                  coins[i][j] + solve(coins, i, j + 1, rem, n, m, dp);
//             down =
//                   coins[i][j] + solve(coins, i + 1, j, rem, n, m, dp);
//         } else {//<0
//             if (rem > 0) // can neutralize robber
//             {
//             right = max(right,  solve(coins, i, j + 1, rem - 1, n, m, dp));
//              down = max(down,    solve(coins, i + 1, j, rem - 1, n, m, dp));

//             } else {
//                 // can't neutralize... give that amount
//                 //** coins[i][j] -> negetive h..to subtract hi hoga*
//                 //   // Can't neutralize, must take the penalty
//                 right = max(right, coins[i][j] + solve(coins, i, j + 1, rem, n, m, dp));
//                 down = max(down, coins[i][j] + solve(coins, i + 1, j, rem, n, m, dp));
//             }
//         }

//         return dp[i][j][rem] = max(right, down);
//     }

//     int maximumAmount(vector<vector<int>>& coins) {

//         int n = coins.size();
//         int m = coins[0].size();
//         vector<vector<vector<int>>> dp(
//             n , vector<vector<int>>(m , vector<int>(3, -1)));//**
//         return solve(coins, 0, 0, 2, n, m, dp);
//     }
// };



class Solution {
public:
// memoize -> TLE
    // int solve(vector<vector<int>>& coins, int i, int j, int rem, int n, int m,
    //           vector<vector<vector<int>>>& dp) {
    //     // Base case: Reached bottom-right corner
    //     if (i == n - 1 && j == m - 1) {
    //         if (coins[i][j] >= 0) {
    //             return coins[i][j];
    //         } else {
    //             return (rem > 0) ? 0 : coins[i][j];
    //         }
    //     }

    //     // Out of bounds
    //     if (i >= n || j >= m)
    //         return -1e9; // Return a very low value for invalid paths

    //     // Check if already computed
    //     if (dp[i][j][rem] != -1)
    //         return dp[i][j][rem];

    //     int right = -1e9, down = -1e9;

    //     // Current cell is positive
    //     if (coins[i][j] >= 0) {
    //         right = coins[i][j] + solve(coins, i, j + 1, rem, n, m, dp);
    //         down = coins[i][j] + solve(coins, i + 1, j, rem, n, m, dp);
    //     }
    //     // Current cell has a robber
    //     else {
    //         if (rem > 0) { // Neutralize robber
    //             right = max(right, solve(coins, i, j + 1, rem - 1, n, m, dp));
    //             down = max(down, solve(coins, i + 1, j, rem - 1, n, m, dp));
    //         }
    //         // Can't neutralize, must take the penalty
    //         right = max(right, coins[i][j] + solve(coins, i, j + 1, rem, n, m, dp));
    //         down = max(down, coins[i][j] + solve(coins, i + 1, j, rem, n, m, dp));
    //     }

    //     // Store the result in DP table
    //     return dp[i][j][rem] = max(right, down);
    // }



    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        // Initialize DP table with -1 (unvisited state)
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1)));
        // return solve(coins, 0, 0, 2, n, m, dp); // Start with 2 neutralizations
    
    
    // # TAB
     int max_rem = 2; // Maximum number of neutralizations available

        // Initialize DP table with -1e9 (representing invalid paths)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(max_rem + 1, -1e9)));

        // Base case: Bottom-right corner
        for (int rem = 0; rem <= max_rem; rem++) {
            dp[n - 1][m - 1][rem] = (coins[n - 1][m - 1] >= 0 || rem > 0)
                                        ? max(0, coins[n - 1][m - 1])
                                        : coins[n - 1][m - 1];
        }

        // Fill the DP table bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                for (int rem = 0; rem <= max_rem; rem++) {
                    // Skip the bottom-right corner (already initialized)
                    if (i == n - 1 && j == m - 1) continue;

                    int right = -1e9, down = -1e9;

                    // Move right
                    if (j + 1 < m) {
                        if (coins[i][j] >= 0) {
                            right = coins[i][j] + dp[i][j + 1][rem];
                        } else if (rem > 0) {
                            right = max(right, dp[i][j + 1][rem - 1]);
                        }
                        right = max(right, coins[i][j] + dp[i][j + 1][rem]);
                    }

                    // Move down
                    if (i + 1 < n) {
                        if (coins[i][j] >= 0) {
                            down = coins[i][j] + dp[i + 1][j][rem];
                        } else if (rem > 0) {
                            down = max(down, dp[i + 1][j][rem - 1]);
                        }
                        down = max(down, coins[i][j] + dp[i + 1][j][rem]);
                    }

                    // Store the maximum value
                    dp[i][j][rem] = max(right, down);
                }
            }
        }

        // Result is stored in dp[0][0][max_rem]
        return dp[0][0][max_rem];
    
    
    }
};
