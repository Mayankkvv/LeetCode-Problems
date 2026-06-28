class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]] ++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> minheap;
        auto it = mpp.begin();
        while(it != mpp.end()){
            minheap.push({it -> second, it -> first});
            if(minheap.size() > k){
                minheap.pop();
            }
            it++;
        }
        vector<int> ans(k);
        for(int i = 0; i < k; i++){
            ans[i] = minheap.top().second;
            minheap.pop();
        }
        return ans;
    }
};