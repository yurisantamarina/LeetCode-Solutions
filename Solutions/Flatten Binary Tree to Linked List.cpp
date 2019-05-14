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
    void Flat(TreeNode* root, vector<TreeNode*>* ord) {
        if (!root) {
            return;
        }
        ord->push_back(root);
        Flat(root->left, ord);
        Flat(root->right, ord);
    }
    
    void flatten(TreeNode* root) {
        vector<TreeNode*> ord;
        Flat(root, &ord);
        
        for (int i = 0; i < (int)ord.size() - 1; i++) {
            ord[i]->right = ord[i + 1];
            ord[i]->left = nullptr;
        }
        
    
    }
};
