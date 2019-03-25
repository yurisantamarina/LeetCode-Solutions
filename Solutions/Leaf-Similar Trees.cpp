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
    bool isLeaf(TreeNode *root) {
        return !root->left && !root->right;   
    }
    
    void dfs(TreeNode* root, vector<int> &leaf_value) {
        if (isLeaf(root)) {
            leaf_value.push_back(root->val);
            return;
        }
        
        if (root->left) dfs(root->left, leaf_value);
        if (root->right) dfs(root->right, leaf_value);
    }
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf_value_1;
        dfs(root1, leaf_value_1);
        
        vector<int> leaf_value_2;
        dfs(root2, leaf_value_2);
        
        return leaf_value_1 == leaf_value_2;
    }
};
