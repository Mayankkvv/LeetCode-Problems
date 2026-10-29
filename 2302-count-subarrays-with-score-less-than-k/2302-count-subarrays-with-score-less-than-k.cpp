class Solution {
using ll = long long;
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll l = 0, r = 0, score = 0, len = 0,cnt = 0, sum = 0;
        while(r < nums.size()){
            sum += nums[r];
            len = r - l + 1;
            score = sum * len;
            while(score >= k){
                sum = sum - nums[l];
                l++;
                len = r - l + 1;
                score = sum * len;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
};