class Solution {
public:
    bool check(string p, string s) {
        int i = 0, j = 0;
        if (s.size() - p.size() != 1)
            return false;
        else {
            while (i < p.size() && j < s.size()) {
                if (p[i] == s[j]) {
                    i++;
                    j++;
                } else {
                    j++;
                }
            }
            return i == p.size();
        }
    }

    static bool cmp(string s1, string s2) { return s1.size() < s2.size(); }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);
        vector<int> t(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[j], words[i])) {
                    t[i] = max(t[i], t[j] + 1);
                    maxi = max(maxi, t[i]);
                }
            }
        }
        return maxi;
    }
};