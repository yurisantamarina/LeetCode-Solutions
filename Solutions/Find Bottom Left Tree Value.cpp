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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});
        vector<int> value(1000000, -1);
        
        TreeNode* at;
        int last_height = 0;
        while (!q.empty()) {
            at = q.front().first;
            last_height = q.front().second;
            q.pop();
            
            if (value[last_height] == -1) value[last_height] = at->val;
            if (at->left) q.push({at->left, last_height + 1});
            if (at->right) q.push({at->right, last_height + 1});
        }
        
        return value[last_height];
    }
};
