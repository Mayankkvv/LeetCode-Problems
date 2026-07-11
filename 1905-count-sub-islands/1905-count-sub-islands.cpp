class Solution {
private:
    bool dfs(int row, int col, vector<vector<int>>& grid1,
             vector<vector<int>>& grid2, vector<vector<int>>& vis, int n,
             int m) {

        vis[row][col] = 1;

        bool isSubIsland = true;

        // If the current cell is water in grid1,
        // then this island cannot be a sub-island.
        if (grid1[row][col] == 0)
            isSubIsland = false;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid2[nrow][ncol] == 1 && !vis[nrow][ncol]) {

                if (!dfs(nrow, ncol, grid1, grid2, vis, n, m))
                    isSubIsland = false;
            }
        }

        return isSubIsland;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {

        int n = grid1.size();
        int m = grid1[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid2[i][j] == 1 && !vis[i][j]) {

                    if (dfs(i, j, grid1, grid2, vis, n, m))
                        count++;
                }
            }
        }

        return count;
    }
};