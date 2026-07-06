class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty() || k == 0)
            return ans;
        // {sum,{i,j}}
        priority_queue<
            pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        // Push first element of each row
        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }
        while (!pq.empty() && k--) {
            auto curr = pq.top();
            pq.pop();
            int i = curr.second.first;
            int j = curr.second.second;
            ans.push_back({nums1[i], nums2[j]});

            // Push next element from the same row
            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }
        return ans;
    }
};