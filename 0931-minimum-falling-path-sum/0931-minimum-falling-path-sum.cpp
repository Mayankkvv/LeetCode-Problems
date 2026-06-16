class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case
        for (int j = 0; j < m; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }

        // Fill from bottom to top
        for (int i = n - 2; i >= 0; i--) {

            for (int j = 0; j < m; j++) {

                int down = matrix[i][j] + dp[i + 1][j];

                int dleft =
                    matrix[i][j] + (j > 0 ? dp[i + 1][j - 1] : (int)1e9);

                int dright =
                    matrix[i][j] + (j < m - 1 ? dp[i + 1][j + 1] : (int)1e9);

                dp[i][j] = min(down, min(dleft, dright));
            }
        }

        int mini = INT_MAX;

        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[0][j]);
        }

        return mini;
    }
};