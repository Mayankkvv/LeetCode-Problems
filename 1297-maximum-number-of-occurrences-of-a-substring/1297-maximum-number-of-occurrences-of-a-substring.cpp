class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> mpp;
        unordered_map<char, int> freq;

        int l = 0;

        for(int r = 0; r < s.size(); r++) {
            freq[s[r]]++;
            if(r - l + 1 > minSize) {
                freq[s[l]]--;
                if(freq[s[l]] == 0)
                    freq.erase(s[l]);

                l++;
            }
            if(r - l + 1 == minSize && freq.size() <= maxLetters) {
                string sub = s.substr(l, minSize);
                mpp[sub]++;
            }
        }
        int ans = 0;
        for(auto it : mpp) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};