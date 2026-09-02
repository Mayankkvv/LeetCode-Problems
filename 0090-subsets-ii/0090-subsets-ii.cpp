class Solution {
private:
    void f(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& ds){
        ans.push_back(ds);
        for(int i = ind; i < nums.size(); i++){
            if(i != ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            f(i+1, nums, ans, ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        f(0, nums, ans, ds);
        return ans;
    }
};