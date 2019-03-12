/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int getLen(ListNode* head){
        int ans = 0;
        while(head){
            head = head->next;
            ans++;
        }
        return ans;
    }
    
    TreeNode* build(ListNode* head, int len){
        if(len == 0)
            return NULL;
        int m = (len / 2);
        ListNode* aux = head;
        for(int i = 0; i < m; i++)
            aux = aux->next;
        
        TreeNode* root = new TreeNode(aux->val);
        root->left = build(head, len / 2);
        root->right = build(aux->next, (len / 2) - (len % 2 == 0 ? 1 : 0));
        return root;
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        int len = getLen(head);
        return build(head, len);
    }
};
