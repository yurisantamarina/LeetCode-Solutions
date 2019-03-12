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
    map<int, TreeNode*> bfs(TreeNode* root, map<int, TreeNode*>& father){
        queue<TreeNode*> q;
        q.push(root);
        father[root->val] = NULL;
        map<int, TreeNode*> height;
        height[root->val] = 0;
        TreeNode* u;
        while(!q.empty()){
            u = q.front();
            q.pop();
            
            if(u->left){
                father[u->left->val] = u;
                height[u->left->val] = height[u->val] + 1;
                q.push(u->left);
            }
            if(u->right){
                father[u->right->val] = u;
                height[u->right->val] = height[u->val] + 1;
                q.push(u->right);
            }
        }
        
        return height;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<int, TreeNode*> father;
        map<int, TreeNode*> height = bfs(root, father);
        
        while(p != q){
            if(height[p->val] >= height[q->val]){
                p = father[p->val];
            }else{
                q = father[q->val];            
            }
        }
        
        return p;
    }
};
