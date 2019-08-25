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
    ListNode* removeZeroSumSublists(ListNode* head) {
        stack<pair<int, ListNode*> > p;
        multiset<int> ms;
        ms.insert(0);
        p.push({0, nullptr});
        while (head) {
            pair<int, ListNode*> at = p.top();
            int acc = at.first + head->val;
            if (ms.find(acc) != ms.end()) { // Zero sum
                while (p.top().first != acc) {
                    ms.erase(ms.find(p.top().first));
                    p.pop();
                }
            } else {
                p.push({acc, head});
                ms.insert(acc);
            }
            head = head->next;
        }
        
        if (p.size() == 1) {
            return nullptr;
        }
        ListNode* lst = nullptr;
        ListNode* cur = nullptr;
        while (p.size() > 1) {
            cur = p.top().second;
            p.pop();
            cur->next = lst;
            lst = cur;
        }
        return cur;
    }
};
