class Solution {
private:
    int f(int i, int j, string& a, string& b, vector<vector<int>>& dp) {
        int n = a.size();
        int m = b.size();
        if(j == m) return n - i;
        if(i == n) return m - j;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]) {
            return dp[i][j] = f(i + 1, j + 1, a, b, dp);
        }
        return dp[i][j] = min({
            f(i, j + 1, a, b,dp),       // insert
            f(i + 1, j, a, b,dp),       // delete
            f(i + 1, j + 1, a, b,dp)    // replace
        }) + 1;
    }

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, word1, word2, dp);
    }
};