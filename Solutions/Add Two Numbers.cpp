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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, a = 0, b = 0, dig = 0;
        ListNode *answer = NULL;
        ListNode *current = NULL;
        while (l1 || l2) {
            a = l1 ? l1->val : 0;
            b = l2 ? l2->val : 0;
            dig = a + b + carry;
            carry = dig >= 10 ? 1 : 0;
            dig %= 10;
            
            if (!answer) {
                answer = new ListNode(dig);
                current = answer;
            } else {
                current->next = new ListNode(dig);
                current = current->next;
            }
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) {
            current->next = new ListNode(1);
        }
        return answer;
    }
};
