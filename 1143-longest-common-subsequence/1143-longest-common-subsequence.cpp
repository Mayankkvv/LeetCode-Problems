class Solution {
private:
    int f(int i, int j, string text1, string text2, vector<vector<int>>& dp){
        int n = text1.size();
        int m = text2.size();
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]) return dp[i][j] = 1 + f(i+1, j+1, text1, text2, dp);
        return dp[i][j] = max(f(i+1, j, text1, text2, dp), f(i, j+1, text1, text2, dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int j = 0; j <= m; j++) dp[n][j] = 0;
        for(int i = 0; i <= n; i++) dp[i][m] = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int j = m -1; j >= 0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};