class Solution {
private:
    int f(int i1, int i2, string& t1, string& t2, vector<vector<int>>& dp){
        if(i1 < 0 || i2 < 0) return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(t1[i1] == t2[i2]) return dp[i1][i2] = 1 + f(i1 -1 , i2 -1 , t1, t2, dp);
        if(t1[i1] != t2[i2]) return dp[i1][i2] = 0 + max(f(i1 - 1, i2, t1, t2,dp), f(i1, i2-1, t1, t2, dp));
        return dp[i1][i2] = 0;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return f(n1-1, n2-1, text1, text2, dp);
    }
};