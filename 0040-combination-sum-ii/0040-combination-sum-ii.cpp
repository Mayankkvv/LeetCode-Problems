class Solution {
private:
    void f(int ind, vector<vector<int>>& ans, vector<int>& ds, int target, vector<int>& candidates){
        if(target == 0){
            ans.push_back(ds);
            return ;
        }
        for(int i = ind; i < candidates.size(); i++){
            if(i != ind && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            f(i +1, ans, ds, target-candidates[i], candidates);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin() , candidates.end());
        f(0 , ans , ds, target, candidates);
        return ans;
    }
};