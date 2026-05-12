class Solution {
private:
    void dfs(int row, int col,
             vector<vector<int>>& ans,
             vector<vector<int>>& image,
             int iniColor, int color) {

        int n = image.size();
        int m = image[0].size();

        ans[row][col] = color;

        // UP
        if (row - 1 >= 0 &&
            image[row - 1][col] == iniColor &&
            ans[row - 1][col] != color) {

            dfs(row - 1, col, ans, image, iniColor, color);
        }

        // RIGHT
        if (col + 1 < m &&
            image[row][col + 1] == iniColor &&
            ans[row][col + 1] != color) {

            dfs(row, col + 1, ans, image, iniColor, color);
        }

        // DOWN
        if (row + 1 < n &&
            image[row + 1][col] == iniColor &&
            ans[row + 1][col] != color) {

            dfs(row + 1, col, ans, image, iniColor, color);
        }

        // LEFT
        if (col - 1 >= 0 &&
            image[row][col - 1] == iniColor &&
            ans[row][col - 1] != color) {

            dfs(row, col - 1, ans, image, iniColor, color);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        dfs(sr, sc, ans, image, iniColor, color);
        return ans;
    }
};