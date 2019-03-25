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
    bool check(TreeNode *root, long long lo, long long hi) {
        if (root == NULL) return true;
        if (root->val < lo || root->val > hi || lo > hi) return false;
        return check(root->left, lo, (long long)root->val - 1) && check(root->right, (long long)root->val + 1, hi);
    }
    
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
