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
    bool check(TreeNode* at_s, TreeNode* at_t){
        if(!at_s && !at_t)
            return true;
        if(!at_s || !at_t || at_s->val != at_t->val)
            return false;
        return check(at_s->left, at_t->left) && check(at_s->right, at_t->right);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s || !t)
            return false;
        if(check(s, t))
            return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
