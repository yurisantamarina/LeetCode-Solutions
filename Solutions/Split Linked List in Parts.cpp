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
    int getSizeList(ListNode* root) {
        int sz_list = 0;
        while (root) {
            sz_list++;
            root = root->next;
        }
        return sz_list;
    }
    
    ListNode* process(ListNode* root, int sz, int qtd, vector<ListNode*>& answer) {
        for (int i = 0; i < qtd; i++) {
            answer.push_back(root);
            for (int j = 0; j < sz - 1; j++) {
                root = root->next;
            }
            if (sz) {
                ListNode* tmp = root->next;
                root->next = NULL;
                root = tmp;
            }
        }
        return root;
    }
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int sz_list = getSizeList(root);
        int size_a, qtd_a, size_b, qtd_b;
        size_a = size_b = sz_list / k;
        if (sz_list % k != 0) {
            size_a++;
        }
        
        qtd_a = sz_list % k;
        qtd_b = k - qtd_a;
        
        vector<ListNode*> answer;
        root = process(root, size_a, qtd_a, answer);
        root = process(root, size_b, qtd_b, answer);
        return answer;
    }
};
