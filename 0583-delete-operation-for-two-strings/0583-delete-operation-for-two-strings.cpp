class Solution {
private:
    int f(int i, int j, string& a, string& b, vector<vector<int>>& dp){
        int n = a.size();
        int m = b.size();
        if(i >= n || j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(a[i] == b[j]){
            return dp[i][j] = 1 + f(i+1, j+1, a, b, dp);
        }
        return dp[i][j] = max(f(i+1, j, a,b, dp), f(i, j+1, a, b, dp));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int len = f(0,0,word1,word2, dp);
        return (n+m) - 2*len;
    }
};