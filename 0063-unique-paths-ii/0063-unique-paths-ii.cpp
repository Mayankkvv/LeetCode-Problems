class Solution {
private:
    int f(int i, int j, vector<vector<int>>& obstacleGrid, int n, int m,
          vector<vector<int>>& dp){
        if(i >= n || j >= m) return 0;
        if(obstacleGrid[i][j] == 1) return 0;
        if(i == n -1 && j == m -1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int right = f(i, j+1, obstacleGrid, n , m,dp);
        int down = f(i+1, j, obstacleGrid, n, m,dp);
        return dp[i][j] = down + right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(0,0,obstacleGrid, n, m,dp);
    }
};