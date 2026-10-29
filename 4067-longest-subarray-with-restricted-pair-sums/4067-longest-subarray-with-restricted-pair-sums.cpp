class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> cntS(2 * mx + 1, 0);
        vector<int> cntD(mx + 1, 0);
        int left = 0, ans = 0;
        for(int right = 0; right < n; right++){
            int x = nums[right];
            while(cntS[x] > 0 || cntD[x] > 0){
                int y = nums[left];
                left++;
                for(int i = left; i < right; i++){
                    int z = nums[i];
                    cntS[y + z]--;
                    cntD[abs(y - z)]--;
                }
            }
            for(int i = left; i < right; i++){
                int y = nums[i];
                cntS[x + y]++;
                cntD[abs(x - y)]++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};