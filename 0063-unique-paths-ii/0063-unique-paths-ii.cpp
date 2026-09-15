class Solution {
private:
    int f(int i, int j, int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i >= row || j >= col || grid[i][j] == 1) return 0;
        if(i == row - 1 && j == col - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int down = f(i+1, j, row, col, grid, dp);
        int right = f(i, j+1, row, col, grid, dp);
        return dp[i][j] = down + right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0,0,m,n, obstacleGrid, dp);
    }
};