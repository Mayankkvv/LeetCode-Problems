class Solution {
public:

    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int mod = 1e9 + 7;

        int n = grid.size();
        int m = grid[0].size();

        // dp[i][j][r]
        // number of ways to reach (i,j)
        // with remainder r

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(m,
            vector<int>(k, 0))
        );

        // Starting cell
        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                for (int rem = 0; rem < k; rem++) {

                    // Move Down
                    if (i + 1 < n) {

                        int newRem =
                        (rem + grid[i + 1][j]) % k;

                        dp[i + 1][j][newRem] =
                        (dp[i + 1][j][newRem] +
                         dp[i][j][rem]) % mod;
                    }

                    // Move Right
                    if (j + 1 < m) {

                        int newRem =
                        (rem + grid[i][j + 1]) % k;

                        dp[i][j + 1][newRem] =
                        (dp[i][j + 1][newRem] +
                         dp[i][j][rem]) % mod;
                    }
                }
            }
        }

        return dp[n - 1][m - 1][0];
    }
};