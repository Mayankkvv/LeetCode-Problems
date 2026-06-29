class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        auto it = mpp.begin();
        while(it != mpp.end()){
            pq.push({it -> second, it -> first});
            it++;
        }
        string ans = "";
        while(!pq.empty()){
            ans.append(pq.top().first, pq.top().second);
            pq.pop();
        }
        return ans;
    }
};