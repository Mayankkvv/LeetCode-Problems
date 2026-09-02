class Solution {
private:
    void f(int ind, vector<vector<int>>& ans, vector<int>& ds,
           vector<int>& vis, vector<int>& nums, int n) {
        // If permutation is complete
        if(ds.size() == n) {
            ans.push_back(ds);
            return;
        }
        // Try every element
        for(int i = 0; i < n; i++) {
            // If already used, skip it
            if(vis[i] == 1)
                continue;
            // Choose
            vis[i] = 1;
            ds.push_back(nums[i]);
            // Recursion
            f(i + 1, ans, ds, vis, nums, n);
            // Backtrack
            ds.pop_back();
            vis[i] = 0;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> vis(n, 0);
        f(0, ans, ds, vis, nums, n);
        return ans;
    }
};