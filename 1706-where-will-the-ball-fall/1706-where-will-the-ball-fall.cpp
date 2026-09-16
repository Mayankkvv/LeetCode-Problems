class Solution {
private:
    int f(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if(j < 0 || j >= n) return -1;
        if(i == m) return j;
        if(grid[i][j] == 1) {
            if(j + 1 < n && grid[i][j + 1] == 1) {
                return f(i + 1, j + 1, m, n, grid);
            }
        }
        else {
            if(j - 1 >= 0 && grid[i][j - 1] == -1) {
                return f(i + 1, j - 1, m, n, grid);
            }
        }
        return -1;
    }

public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = f(0, i, m, n, grid);
        }
        return ans;
    }
};