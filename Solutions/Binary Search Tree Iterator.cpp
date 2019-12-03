/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if (root) {
            curr_nodes.push({root, NextChildToConsider::L});
        }
    }
    
    /** @return the next smallest number */
    int next() {
        while (true) {
            pair<TreeNode*, NextChildToConsider>& node = curr_nodes.top();
            if (node.second == NextChildToConsider::L) {
                node.second = NextChildToConsider::R;
                if (node.first->left) {
                    curr_nodes.push({node.first->left, NextChildToConsider::L});
                }
            } else {
                int next_node = node.first->val;
                if (node.first->right) {
                    curr_nodes.top() = {node.first->right, NextChildToConsider::L};
                } else {
                    curr_nodes.pop();
                }
                return next_node;
            }
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !curr_nodes.empty();
    }
private:
    enum NextChildToConsider {L, R};
    stack<pair<TreeNode*, NextChildToConsider>> curr_nodes;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
