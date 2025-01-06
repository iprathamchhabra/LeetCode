class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
        return false;
    }
    unordered_map<char, int> charCount;

    for (char c : s) {
        charCount[c]++;
    }
    for (char c : t) {
        charCount[c]--;
        if (charCount[c] < 0) {
            return false;
        }
    }

    return true;
        
    }
};