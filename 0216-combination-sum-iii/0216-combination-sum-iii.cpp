class Solution {
private:
    void f(int i, int sum, vector<vector<int>>& ans, vector<int>& ds, int k, int n) {
        if (k == 0) {
            if (sum == n) ans.push_back(ds);
            return;
        }
        if (i > 9) return;
        if (sum > n) return; 

        // pick i
        ds.push_back(i);
        f(i + 1, sum + i, ans, ds, k - 1, n);
        ds.pop_back();

        // not pick i
        f(i + 1, sum, ans, ds, k, n);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(1, 0, ans, ds, k, n);
        return ans;
    }
};
