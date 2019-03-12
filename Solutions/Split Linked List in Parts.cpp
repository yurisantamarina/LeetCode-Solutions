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
    int getLen(ListNode* root){
        int len = 0;
        while(root != NULL){
            root = root->next;
            len++;
        }
        return len;
    }
    
    ListNode* move(int times, int sz, ListNode* at, vector<ListNode*>& ans){
        while(times > 0){
            ListNode* newRoot = at;
            ans.push_back(newRoot);
            
            for(int i = 0; i < sz - 1; i++){
                newRoot = newRoot->next;
            }
            at = newRoot ? newRoot->next : NULL;
            if(newRoot)
                newRoot->next = NULL;
            times--;
        }
        return at;
    }
    
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = getLen(root);
        //printf("n = %d\n", n);
        int sizeMore = n / k + (n % k > 0);
        int more = n % k;
        int sizeLess = n / k;
        int less = k - more;
        
        //printf("sizeMore = %d more = %d    sizeLess = %d less = %d\n", sizeMore, more, sizeLess, less);
        ListNode* at = root;
        vector<ListNode*> ans;
        
        at = move(more, sizeMore, at, ans);
        at = move(less, sizeLess, at, ans);
        return ans;
    }
};
