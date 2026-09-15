class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        dp[n - 1][m - 1] = grid[n - 1][m - 1];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (i == n - 1 && j == m - 1) {
                    dp[i][j] = grid[i][j];
                } else {

                    int right = INT_MAX;
                    int down = INT_MAX;

                    if (j + 1 < m)
                        right = grid[i][j] + dp[i][j + 1];

                    if (i + 1 < n)
                        down = grid[i][j] + dp[i + 1][j];

                    dp[i][j] = min(right, down);
                }
            }
        }

        return dp[0][0];
    }
};