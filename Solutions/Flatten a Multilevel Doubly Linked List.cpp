/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    
    void Flat(Node* head, vector<Node*>* order) {
        if (!head) {
            return;
        }
        order->push_back(head);
        Flat(head->child, order);
        Flat(head->next, order);
    }
    
    Node* flatten(Node* head) {
        if (!head) {
            return nullptr;
        }
        vector<Node*> order;
        Flat(head, &order);
        
        for (int i = 0; i < (int)order.size(); i++) {
            order[i]->next = nullptr;
            order[i]->child = nullptr;
            
            if (i + 1 < (int)order.size()) {
                order[i]->next = order[i + 1];
                order[i + 1]->prev = order[i];
            }
        }
        
        return order[0];
    }
};
