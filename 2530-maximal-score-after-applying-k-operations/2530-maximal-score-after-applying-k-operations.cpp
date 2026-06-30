class Solution {
public:
    typedef long long ll;
    long long maxKelements(vector<int>& nums, int k) {
        ll score = 0;
        priority_queue<ll> pq;
        for(auto it:nums){
            pq.push(it);
        }
        for(int i = 0; i< k; i++){
            int num = pq.top();
            pq.pop();
            score += num;
            pq.push((num + 2)/3);
        }
        return score;
    }
};