class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < piles.size(); i++){
            pq.push(piles[i]);
        }
        for(int i = 1; i <= k; i++){
            int num = pq.top();
            pq.pop();
            pq.push(ceil(num/2.0));
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};