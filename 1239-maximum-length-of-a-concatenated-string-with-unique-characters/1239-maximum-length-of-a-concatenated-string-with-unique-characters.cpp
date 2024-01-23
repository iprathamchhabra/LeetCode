class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> masks = {0};
        int res = 0;
        for (const string& s : arr) {
            int mask = 0, dup = 0;
            for (char c : s) {
                dup |= mask & (1 << (c - 'a'));
                mask |= 1 << (c - 'a');
            }
            if (dup) continue;
            for (int i = masks.size() - 1; i >= 0; --i) {
                if (masks[i] & mask) continue;
                masks.push_back(masks[i] | mask);
                res = max(res, __builtin_popcount(masks.back()));
            }
        }
        return res;
    }
};
