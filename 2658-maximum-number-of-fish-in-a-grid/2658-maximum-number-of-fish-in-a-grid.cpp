class Solution {
private:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis, int n, int m){
        vis[row][col] = 1;
        int drow[4] = {0, 0, +1, -1};
        int dcol[4] = {+1, -1,0, 0};
        int fish = grid[row][col];
        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] > 0 && vis[nrow][ncol] == 0){
                fish += dfs(nrow, ncol, grid, vis, n, m);
            }
        }
        return fish;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxFish = 0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] > 0 && !vis[i][j]){
                maxFish = max(maxFish, dfs(i, j, grid, vis, n, m));
            }
            }
        }
        return maxFish;
    }
};