class Solution {
private:
    void dfs(int sr, int sc, int color, vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();
        int oldCol = image[sr][sc];
        image[sr][sc] = color;
        int drow[4] = {-1, 0, +1, 0};
        int dcol[4] = {0, +1, 0, -1};
        for(int i = 0; i < 4; i++) {
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
               image[nrow][ncol] == oldCol) {
                dfs(nrow, ncol, color, image);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        if(image[sr][sc] == color) return image;
        dfs(sr, sc, color, image);
        return image;
    }
};