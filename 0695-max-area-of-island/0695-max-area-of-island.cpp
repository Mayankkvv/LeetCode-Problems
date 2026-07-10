class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& vis, int n, int m) {
        vis[row][col] = 1;
        int area = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                area += dfs(nrow, ncol, grid, vis, n, m);
            }
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    maxArea = max(maxArea, dfs(i, j, grid, vis, n, m));
                }
            }
        }
        return maxArea;
    }
};