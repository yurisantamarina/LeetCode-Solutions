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
    int FindHeight(TreeNode* root) {
        int height = -1;
        while (root) {
            root = root->left;
            height++;
        }
        return height;
    }
    
    bool ExistsInTree(TreeNode* root, int node_val, int L, int R) {
        while (root) {
            if (L == R) {
                return true;
            }
            int middle = (L + R) / 2;
            if (node_val <= middle) {
                root = root->left;
                R = middle;
            } else {
                root = root->right;
                L = middle + 1;
            }
        }
        return false;
    }
    
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int height = FindHeight(root);
        int total_nodes = (1 << height) - 1;
        int begin_last_level = 1 << height;
        int end_last_level = (1 << (height + 1)) - 1;
        int lo = begin_last_level;
        int hi = end_last_level;
        int last_node = lo;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (ExistsInTree(root, mid, begin_last_level, end_last_level)) {
                lo = mid + 1;
                last_node = mid;
            } else {
                hi = mid - 1;
            }
        }
        return total_nodes + last_node - begin_last_level + 1;
    }
};
