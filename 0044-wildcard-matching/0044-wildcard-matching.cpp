class Solution {
private:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        int n = s.size();
        int m = p.size();
        if(i == n && j == m) return true;
        if(j == m) return false;
        if(i == n){
            for(int k = j; k < m; k++){
                if(p[k] != '*')
                    return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(p[j] == '*'){
            return dp[i][j] = f(i, j+1, s, p,dp) ||
                   f(i+1, j, s, p,dp);
        }
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = f(i+1, j+1, s, p,dp);
        }
        return dp[i][j] = false;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(0, 0, s, p, dp);
    }
};