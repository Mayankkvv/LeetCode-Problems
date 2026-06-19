class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0;
        int cnt = 0;
        vector<int> freq(3, 0);
        for (int r = 0; r < n; r++) {
            freq[s[r] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                cnt += n - r;
                freq[s[l] - 'a']--;
                l++;
            }
        }
        return cnt;
    }
};