class Solution {
private:
    void f(int ind, vector<int>& nums, vector<vector<int>>& ans, 
    vector<int>& store, int n){
        if(ind >= n){
            ans.push_back(store);
            return ;
        }
        store.push_back(nums[ind]);
        f(ind + 1, nums,ans,store,n);
        store.pop_back();
        f(ind + 1, nums,ans,store,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> store;
        f(0, nums,ans, store, n);
        return ans;
    }
};