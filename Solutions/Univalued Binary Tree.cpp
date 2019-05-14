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
    bool isUnivalTree(TreeNode* root) {
        bool ans = true;
        if (root->left) {
            ans = ans && (root->val == root->left->val) && isUnivalTree(root->left);
        }
        if (root->right) {
            ans = ans && (root->val == root->right->val) && isUnivalTree(root->right);
        }
        
        return ans;
    }
};
