/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int& ans_tot) {
        if (!root) {
            return 0;
        }
        int ans = 1;
        if (root->left) {
            int ans_left = dfs(root->left, ans_tot);
            if (root->val + 1 == root->left->val) {
                ans_left++;
            } else {
                ans_left = 0;
            }
            ans = max(ans, ans_left);
        }
        if (root->right) {
            int ans_right = dfs(root->right, ans_tot);
            if (root->val + 1 == root->right->val) {
                ans_right++;
            } else {
                ans_right = 0;
            }
            ans = max(ans, ans_right);
        }
        ans_tot = max(ans_tot, ans);
        return ans;
    }
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
