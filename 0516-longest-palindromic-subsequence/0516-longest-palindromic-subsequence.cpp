class Solution {
private:
    int f(int i, int j , string& s, vector<vector<int>>& dp){
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = 2 + f(i+1, j-1, s, dp);
        int a = f(i + 1, j , s, dp);
        int b = f(i, j-1, s, dp);
        return dp[i][j] = max(a,b);
    }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, s.size() - 1, s, dp);
    }
};