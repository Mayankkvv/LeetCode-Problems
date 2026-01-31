class Solution {
private:
    void f(int ind, int sum, vector<vector<int>>&ans, vector<int>& ds, vector<int>& candidates, int target){
        if(sum == target){
            ans.push_back(ds);
            return ;
        }
        if(sum > target) return ;
        if(ind >= candidates.size()){
            if(sum == target){
                ans.push_back(ds);
            }
            return ;
        }
        ds.push_back(candidates[ind]);
        sum += candidates[ind];
        f(ind, sum, ans , ds, candidates, target);

        ds.pop_back();
        sum-=candidates[ind];
        f(ind+1, sum, ans,ds, candidates, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(0, 0, ans , ds, candidates, target);
        return ans;
    }
};