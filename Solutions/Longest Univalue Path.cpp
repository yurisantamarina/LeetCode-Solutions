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
    int dfs(TreeNode* root, int& answer) {
        if (!root) {
            return 0;
        }
        int L = INT_MAX;
        int R = INT_MAX;
        int aux = 1;
        if (root->left) {
            L = dfs(root->left, answer);
            if (root->val == root->left->val) {
                aux = max(aux, L + 1);
            }
        }
        if (root->right) {
            R = dfs(root->right, answer);
            if (root->val == root->right->val) {
                aux = max(aux, R + 1);
            }
        }
        if (L != INT_MAX && R != INT_MAX && root->val == root->left->val && root->val == root->right->val) {
            answer = max(answer, L + R);
        }
        answer = max(answer, aux - 1);
        return aux;
    }
    int longestUnivaluePath(TreeNode* root) {
        int answer = 0;
        dfs(root, answer);
        return answer;
    }
};
