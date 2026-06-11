class Solution {
private:
    bool isPalindrome(int i , int j, string& s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
private:
    int f(int ind, int n, string& s, vector<int>& dp){
        if(ind == n) return 0;
        if(dp[ind]!= -1) return dp[ind];
        int minCost = INT_MAX;  
        for(int i = ind; i < n; i++){
            if(isPalindrome(ind, i, s)){
                int cost = 1 + f(i + 1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[ind] = minCost;
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, n, s, dp) - 1;
    }
};