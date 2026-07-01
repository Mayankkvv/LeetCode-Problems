class Solution {
public:
    typedef long long ll;

    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        // {{nums1, nums2}, originalIndex}
        vector<pair<pair<int, int>, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({{nums1[i], nums2[i]}, i});
        }
        sort(arr.begin(), arr.end());
        vector<ll> ans(n);
        // Min heap to keep the largest k values of nums2
        priority_queue<int, vector<int>, greater<int>> pq;
        ll sum = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            // Assign answers for all elements having the same nums1
            while (j < n && arr[j].first.first == arr[i].first.first) {
                ans[arr[j].second] = sum;
                j++;
            }
            // Insert their nums2 values into the heap
            while (i < j) {
                int val = arr[i].first.second;
                pq.push(val);
                sum += val;
                if (pq.size() > k) {
                    sum -= pq.top();
                    pq.pop();
                }
                i++;
            }
        }
        return ans;
    }
};