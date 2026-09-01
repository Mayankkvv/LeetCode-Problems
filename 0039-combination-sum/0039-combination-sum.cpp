class Solution {
private:
    void f(int ind,int sum, vector<int>& arr, int target, vector<vector<int>>& ans, vector<int>& ds, int n){
        if(sum > target) return ;
        if(sum == target){
            ans.push_back(ds);
            return ;
        }
        if(ind >= n){
            if(sum == target){
                ans.push_back(ds);
            }
            return ;
        }
        ds.push_back(arr[ind]);
        sum += arr[ind];
        f(ind, sum, arr, target, ans, ds, n);
        sum -= arr[ind];
        ds.pop_back();
        f(ind+1, sum, arr, target, ans, ds, n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        f(0,0, candidates, target, ans, ds, n);
        return ans;
    }
};