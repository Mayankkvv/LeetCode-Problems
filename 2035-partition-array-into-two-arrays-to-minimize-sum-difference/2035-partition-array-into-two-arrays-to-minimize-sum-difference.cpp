class Solution {
public:
    int minimumDifference(vector<int>& nums) {

        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>> leftSums(n + 1);
        vector<vector<int>> rightSums(n + 1);

        // Generate subset sums for left half
        for (int mask = 0; mask < (1 << n); mask++) {

            int sum = 0;
            int cnt = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    sum += left[i];
                    cnt++;
                }
            }

            leftSums[cnt].push_back(sum);
        }

        // Generate subset sums for right half
        for (int mask = 0; mask < (1 << n); mask++) {

            int sum = 0;
            int cnt = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {
                    sum += right[i];
                    cnt++;
                }
            }

            rightSums[cnt].push_back(sum);
        }

        for (int i = 0; i <= n; i++) {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        int ans = INT_MAX;

        for (int leftCount = 0; leftCount <= n; leftCount++) {

            int rightCount = n - leftCount;

            for (int leftSum : leftSums[leftCount]) {

                double target =
                    (double)total / 2 - leftSum;

                auto& vec = rightSums[rightCount];

                auto it = lower_bound(
                    vec.begin(),
                    vec.end(),
                    target);

                if (it != vec.end()) {

                    int chosen =
                        leftSum + *it;

                    int diff =
                        abs(total - 2 * chosen);

                    ans = min(ans, diff);
                }

                if (it != vec.begin()) {

                    --it;

                    int chosen =
                        leftSum + *it;

                    int diff =
                        abs(total - 2 * chosen);

                    ans = min(ans, diff);
                }
            }
        }

        return ans;
    }
};