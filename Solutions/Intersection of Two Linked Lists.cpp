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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while(a && b){
            if(a->val == b->val) return a;
            if(a->val > b->val) b = b->next;
            else a = a->next;
        }
        
        return NULL;
    }
};
