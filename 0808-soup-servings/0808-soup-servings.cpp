class Solution {
private:
    double f(int a, int b, vector<pair<double,double>>& steps,vector<vector<double>> &dp){
        if(a <= 0 && b <=0) return 0.5;
        if(a <= 0) return 1.0;
        if(b <= 0) return 0.0;
        if(dp[a][b] != -1) return dp[a][b];
        double prob = 0.0;
        for(auto& it: steps){
            double a_serve = it.first;
            double b_serve = it.second;
            prob += 0.25* f(a-a_serve, b - b_serve, steps,dp);
        }
        return dp[a][b] = prob;
    }
public:
    double soupServings(int n) {
        if(n >= 5000) return 1.0;
        vector<pair<double, double>> steps = {{100,0}, {75,25}, {50,50}, {25,75}};
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        return f(n,n, steps, dp);
    }
};