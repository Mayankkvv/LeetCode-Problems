class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> mp;

        for (char c : s)
            mp[c]++;

        priority_queue<pair<int, char>> pq;

        for (auto &it : mp)
            pq.push({it.second, it.first});

        string ans = "";

        while (!pq.empty()) {

            auto first = pq.top();
            pq.pop();
            if (ans.empty() || ans.back() != first.second) {

                ans += first.second;
                first.first--;

                if (first.first > 0)
                    pq.push(first);
            }
            else {
                if (pq.empty())
                    return "";

                auto second = pq.top();
                pq.pop();

                ans += second.second;
                second.first--;

                if (second.first > 0)
                    pq.push(second);
                pq.push(first);
            }
        }
        return ans;
    }
};