class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> st, dp(n , 0);
        for(int i = n - 1; i >= 0; --i){
            int steps = 0;
            while(!st.empty() && nums[i] > nums[st.back()]){
                steps = max(steps + 1 , dp[st.back()]);
                st.pop_back();
            }
            st.push_back(i);
            dp[i] = steps;
            res = max(res , steps);
        }
        return res;
    }
};