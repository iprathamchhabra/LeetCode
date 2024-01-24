/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        std::unordered_map<int, int> mp;
        int count = 0;
        dfs(root, mp, count);
        return count;
    }

    void dfs(TreeNode* node, std::unordered_map<int, int>& mp, int& count) {
        if (node) {
            mp[node->val]++;
            if (!node->left && !node->right) {
                if (isPseudoPalindromic(mp)) {
                    count++;
                }
            }
            dfs(node->left, mp, count);
            dfs(node->right, mp, count);
            mp[node->val]--;
        }
    }
    bool isPseudoPalindromic(const std::unordered_map<int, int>& mp) {
        int oddCount = 0;
        for (const auto& entry : mp) {
            if (entry.second % 2 != 0) {
                oddCount++;
            }
        }
        return oddCount <= 1;
    }
};