class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0;
        int m = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                int j = i;
                while (j < nums.size() && nums[j] == 1) {
                    c++;
                    j++;
                }
                m = max(c, m);
                c = 0;
                i = j;
            }
        }
        return m;
    }
};