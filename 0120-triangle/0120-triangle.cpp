class Solution {
private:
    int f(int i,int j, int rows,vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i == rows) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int a = triangle[i][j] + f(i + 1, j, rows, triangle, dp);
        int b = triangle[i][j] + f(i+1, j+ 1, rows, triangle, dp);
        return dp[i][j] = min(a,b);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<vector<int>> dp(rows, vector<int>(rows,0));
        for(int i = 0; i < rows ; i++){
            dp[rows-1][i] = triangle[rows-1][i];
        }
        for(int i = rows - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                int a = triangle[i][j] + dp[i+1][j];
                int b = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(a,b);
            }
        }
        return dp[0][0];
        //return f(0,0,rows - 1,triangle, dp);
    }
};