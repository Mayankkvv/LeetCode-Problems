class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, maxSum = 0;
        for(int i = 0; i < k; i++){
            lsum += cardPoints[i];
        }
        maxSum = lsum;
        int rsum = 0, rindex = cardPoints.size() - 1;
        for(int i = k-1; i>=0; i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rindex];
            rindex--;
            maxSum = max(maxSum , lsum + rsum);
        }
        return maxSum;
    }
};