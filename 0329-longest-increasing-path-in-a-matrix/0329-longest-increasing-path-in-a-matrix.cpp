class Solution {
private:
    int f(int i, int j,int prev, vector<vector<int>>& matrix, int n, int m,
            vector<vector<int>>& dp){
        if(i < 0 || j < 0 || i >= n|| j >= m|| matrix[i][j] <= prev)
            return 0;
        if(dp[i][j] != - 1) return dp[i][j];

        int maxPath = 1;

        maxPath = max(maxPath, 1 + f(i, j -1, matrix[i][j], matrix, n, m, dp));
        maxPath = max(maxPath, 1 + f(i, j + 1, matrix[i][j], matrix, n, m, dp));
        maxPath = max(maxPath, 1 + f(i - 1,j , matrix[i][j], matrix, n, m, dp));
        maxPath = max(maxPath, 1 + f(i + 1,j , matrix[i][j], matrix, n, m, dp));

        return dp[i][j] = maxPath;


    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = INT_MIN;
        vector<vector<int>>dp(n, vector<int>(m, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j< m; j++){
                int path = f(i, j,-1, matrix, n, m, dp);
                maxi = max(maxi, path);
            }
        }
        return maxi;
    }
};