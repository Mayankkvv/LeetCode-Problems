class Solution {
private:
    int f(int i , int j, int m, int n, vector<vector<int>> &dp){
        if(i >=m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == m - 1 && j == n - 1) return 1;
        int down = f(i + 1, j, m, n, dp);
        int right = f(i , j + 1, m, n, dp);
        return dp[i][j] = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[m-1][n-1] = 1;
        for(int i = m - 1; i >= 0 ; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i == m - 1 && j == n - 1) continue;
                int down = dp[i][j+1];
                int right = dp[i+1][j];
                dp[i][j] = down + right;
            }
        }
        return dp[0][0];
    }
};