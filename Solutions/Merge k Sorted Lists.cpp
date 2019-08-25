/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    struct compare {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* last_node = nullptr;
        ListNode* head = nullptr;
        
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }
        
        while (!pq.empty()) {
            ListNode* curr_node = pq.top();
            pq.pop();
            
            if (head == nullptr) {
                head = curr_node;
            } else {
                last_node->next = curr_node;
            }
            last_node = curr_node;
            if (curr_node->next) {
                pq.push(curr_node->next);
            }
        }
        
        
        return head;
    }
};
