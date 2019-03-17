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
    TreeNode* solve(vector<int>& preorder, vector<int>& nxt, int l, int r){
        TreeNode* root = (TreeNode*) malloc(sizeof(TreeNode));
        root->val = preorder[l];
        root->left = root->right = NULL;
        
        if(l < (int)preorder.size() - 1 && preorder[l + 1] < preorder[l])
            root->left = solve(preorder, nxt, l + 1, nxt[l] - 1);
        if(nxt[l] <= r)
            root->right = solve(preorder, nxt, nxt[l], r);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> nxt((int)preorder.size(), (int)preorder.size());
        stack<int> st;
        for(int i = (int)preorder.size() - 1; i >= 0; i--){
            while((int)st.size() > 0 && preorder[i] > preorder[st.top()])
                st.pop();
            if(!st.empty())
                nxt[i] = st.top();
            st.push(i);
        }
        return solve(preorder, nxt, 0, (int)preorder.size() - 1);
    }
};
