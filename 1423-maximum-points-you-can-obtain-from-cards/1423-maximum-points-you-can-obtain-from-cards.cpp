class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int rindex = n -1;
        int leftsum = 0, rightsum = 0;
        for(int i = 0; i < k; i++){
            leftsum += cardPoints[i];
        }
        int maxSum = leftsum;
        for(int i = k - 1; i >= 0; i--){
            leftsum -= cardPoints[i];
            rightsum += cardPoints[rindex];            //TC -> O(K) + O(K)
            rindex--;                                  // SC -> O(1)
            maxSum = max(maxSum, leftsum + rightsum );
        }
        return maxSum;
    }
};