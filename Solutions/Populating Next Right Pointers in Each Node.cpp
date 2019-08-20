/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        Node* curr_node_above = root;
        Node* last_node = nullptr;
        Node* first_node_in_curr_level = nullptr;
        
        while (curr_node_above) {
            if (curr_node_above->left) {
                if (!first_node_in_curr_level) {
                    first_node_in_curr_level = curr_node_above->left;
                }
                if (last_node) {
                    last_node->next = curr_node_above->left;
                }
                last_node = curr_node_above->left;
            }
            
            if (curr_node_above->right) {
                if (!first_node_in_curr_level) {
                    first_node_in_curr_level = curr_node_above->right;
                }
                if (last_node) {
                    last_node->next = curr_node_above->right;
                }
                last_node = curr_node_above->right;
            }
            
            if (curr_node_above->next) {
                curr_node_above = curr_node_above->next;
            } else {
                curr_node_above = first_node_in_curr_level;
                last_node = nullptr;
                first_node_in_curr_level = nullptr;
            }
        }
        
        return root;
    }
    
};
