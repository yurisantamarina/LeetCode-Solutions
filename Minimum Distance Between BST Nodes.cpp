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
    void preOrder(TreeNode* root, vector<int> &pre){
        if(root == NULL)
            return;
        preOrder(root->left, pre);
        pre.push_back(root->val);
        preOrder(root->right, pre);
    }
    
    int minDiffInBST(TreeNode* root) {
        vector<int> pre;
        preOrder(root, pre);
        int ans = 100000000;
        for(int i = 1; i < (int)pre.size(); i++)
            ans = min(ans, pre[i] - pre[i - 1]);
        return ans;
    }
};
