class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size();

        vector<int> lis(n, 1);
        vector<int> lds(n, 1);

        // LIS ending at i
        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(nums[prev] < nums[i]) {
                    lis[i] = max(lis[i], 1 + lis[prev]);
                }
            }
        }

        // LDS starting at i
        for(int i = n - 1; i >= 0; i--) {
            for(int next = n - 1; next > i; next--) {
                if(nums[next] < nums[i]) {
                    lds[i] = max(lds[i], 1 + lds[next]);
                }
            }
        }

        int maxMountain = 0;

        for(int i = 0; i < n; i++) {

            // valid peak
            if(lis[i] > 1 && lds[i] > 1) {

                maxMountain =
                    max(maxMountain,
                        lis[i] + lds[i] - 1);
            }
        }

        return n - maxMountain;
    }
};