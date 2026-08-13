class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;

        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;

        while (l < n) {
            r = l;
            cnt = 0;
            vector<int> sub;

            while (r < n) {
                sub.push_back(nums[r]);

                if (nums[r] % p == 0)
                    cnt++;

                if (cnt > k)
                    break;

                st.insert(sub);
                r++;
            }

            l++;
        }

        return st.size();
    }
};