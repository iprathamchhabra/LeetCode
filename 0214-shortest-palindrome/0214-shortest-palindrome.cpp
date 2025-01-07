class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return ""; 

        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string combined = s + "#" + rev_s;

        vector<int> lps(combined.length(), 0);
        for (int i = 1; i < combined.length(); i++) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j;
        }

        int palindromicPrefixLength = lps.back();
        string toAdd = rev_s.substr(0, n - palindromicPrefixLength);
        return toAdd + s;
    }
};