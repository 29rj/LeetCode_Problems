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
    ListNode *gb;
    
    ListNode * helper(ListNode *head){
        
       if(head == NULL){
           return NULL;
       }
        
        ListNode *temp = head -> next; //2
        
        head -> next = helper(head -> next);
        
        if(temp!=NULL)
            temp->next = head;
        else{
            gb = head;
        }
        
        return head;
    }

    ListNode* reverseList(ListNode* head) {
        
        if(head == NULL)
            return NULL;
        
        ListNode*temp = helper(head);
        
        temp -> next = NULL;
        
        return gb;
    }
};