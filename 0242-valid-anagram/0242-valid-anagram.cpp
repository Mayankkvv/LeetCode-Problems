class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int arr1[26] = {0};
        int arr2[26] = {0};
        for(int i = 0; i < t.size(); i++){
            arr1[t[i] - 'a']++;
            arr2[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }
};