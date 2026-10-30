
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();
        int leftK = 0, leftM = 0;
        int good = 0;
        long long ans = 0;
        unordered_map<int, int> freqK, freqM;
        for(int right = 0; right < n; right++) {
            freqK[nums[right]]++;
            while(freqK.size() > k) {
                freqK[nums[leftK]]--;
                if(freqK[nums[leftK]] == 0) {
                    freqK.erase(nums[leftK]);
                }
                leftK++;
            }
            freqM[nums[right]]++;
            if(freqM[nums[right]] == m) {
                    good++;
                }
            while(good >= k) {
                if(freqM[nums[leftM]] == m) {
                    good--;
                }
                freqM[nums[leftM]]--;
                if(freqM[nums[leftM]] == 0) {
                    freqM.erase(nums[leftM]);
                }
                leftM++;
            }
            if(leftM > leftK) {
                ans += leftM - leftK;
            }
        }
        return ans;
    }
};
