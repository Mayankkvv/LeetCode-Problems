class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int ind = 0;
        while(ind < n && intervals[ind][1] < newInterval[0]){ //left part
            ans.push_back(intervals[ind]);
            ind++;
        }
        while(ind < n && intervals[ind][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[ind][0]);
            newInterval[1] = max(newInterval[1], intervals[ind][1]);
            ind++;
        }
        ans.push_back(newInterval);
        while(ind < n){
            ans.push_back(intervals[ind]);
            ind++;
        }
        return ans;
    }
};