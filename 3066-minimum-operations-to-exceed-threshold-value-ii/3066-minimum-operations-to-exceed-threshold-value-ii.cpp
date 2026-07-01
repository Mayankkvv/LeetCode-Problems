class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        for (int x : nums)
            minHeap.push(x);

        int ans = 0;

        while (minHeap.size() > 1 && minHeap.top() < k) {

            long long num1 = minHeap.top();
            minHeap.pop();

            long long num2 = minHeap.top();
            minHeap.pop();

            minHeap.push(num1 * 2 + num2);

            ans++;
        }

        return ans;
    }
};