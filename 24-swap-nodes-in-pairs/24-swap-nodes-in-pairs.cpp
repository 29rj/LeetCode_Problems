/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode* prev = head,*curr = head -> next,*pprev = NULL;
        
        ListNode*newHead=head->next;
        
        while(curr != NULL && prev != NULL) {
            
            ListNode* temp = curr->next;
            curr -> next = prev;
            prev -> next = temp;
            
            if(pprev){
                pprev -> next = curr;
            }
            
            pprev = prev;
            prev = temp;
            if(prev)
                curr = prev -> next;
        }
        
        return newHead;
    }
};