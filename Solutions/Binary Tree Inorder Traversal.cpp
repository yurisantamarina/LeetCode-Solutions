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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        
        enum Type {LEFT, RIGHT};
        stack<pair<TreeNode*, Type>> nodes;
        vector<int> inorder;
        
        nodes.push(make_pair(root, Type::LEFT));
        
        TreeNode* curr_node;
        Type op;
        while (!nodes.empty()) {
            curr_node = nodes.top().first;
            op = nodes.top().second;
            nodes.pop();
            if (op == Type::LEFT) {
                nodes.push(make_pair(curr_node, Type::RIGHT));
                if (curr_node->left) {
                    nodes.push(make_pair(curr_node->left, Type::LEFT));
                }
            } else {
                inorder.push_back(curr_node->val);
                if (curr_node->right) {
                    nodes.push(make_pair(curr_node->right, Type::LEFT));
                }
            }
        }
        
        return inorder;
    }
};