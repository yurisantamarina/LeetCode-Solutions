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
    
    // Kind of reverse inorder traversal (decreasing order of root->val)
    void Convert(TreeNode* root, int& glob) {
        if (root == nullptr) {
            return;
        }
        int original = root->val;
        Convert(root->right, glob);
        root->val += glob; // at this point all the nodes with key > root->val has already been visited
        glob += original;
        Convert(root->left, glob);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int glob = 0;
        Convert(root, glob);
        return root;
    }
};
