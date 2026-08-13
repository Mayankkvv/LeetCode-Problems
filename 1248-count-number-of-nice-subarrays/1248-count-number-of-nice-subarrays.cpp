class Solution {
private:
    int f(vector<int>& nums, int k){
        if(k < 0) return 0;
        int l = 0, r = 0, cnt = 0;
        int ans = 0;
        while(r < nums.size()){
            if(nums[r] % 2 == 1){
                cnt++;
            }
            while(cnt > k){
                if(nums[l] % 2 == 1){
                    cnt--;
                }
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k -1);
    }
};