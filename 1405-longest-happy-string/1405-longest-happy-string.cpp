class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        string ans = "";
        while (!pq.empty()) {
            auto first = pq.top();
            pq.pop();
            int cnt1 = first.first;
            char ch1 = first.second;
            // If adding ch1 creates three consecutive same characters
            if (ans.size() >= 2 && ans.back() == ch1 && ans[ans.size() - 2] == ch1) {
                // No other character is available
                if (pq.empty())
                    break;
                auto second = pq.top();
                pq.pop();
                int cnt2 = second.first;
                char ch2 = second.second;
                // Use second largest character
                ans += ch2;
                cnt2--;
                if (cnt2 > 0)
                    pq.push({cnt2, ch2});
                // Put the first character back
                pq.push(first);
            }
            else {
                // Safe to use the most frequent character
                ans += ch1;
                cnt1--;

                if (cnt1 > 0)
                    pq.push({cnt1, ch1});
            }
        }
        return ans;
    }
};