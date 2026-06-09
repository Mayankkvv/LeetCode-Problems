class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;

        vector<int> buy(k+1, INT_MAX);
        vector<int> profit(k+1, 0);

        for (int price : prices) {
            for (int i = 1; i <= k; i++) {
                buy[i] = min(buy[i], price-profit[i-1]);
                profit[i] = max(profit[i], price-buy[i]);
            }
        }

        return profit[k];
    }
};