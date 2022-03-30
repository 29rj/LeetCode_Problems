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
    bool isPalindrome(ListNode* head) {
        
        if(head -> next == NULL)
            return true;
        
        //slow and fast method --> middle element
        ListNode* slow = head, *fast = head,*yemp=NULL;
        
        while(fast!=NULL && fast->next != NULL){
            yemp = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        yemp -> next = NULL;
        
        // cout << slow -> val << " ";
        
        //reverse from slow
        ListNode *curr = slow , *prev = NULL;
        
        if(curr == NULL)
            prev = slow;
        
        while(curr!=NULL){
            
            ListNode *now = curr->next;
            curr->next = prev;
            prev = curr;
            curr = now;
            
        }
        
//         while(head != NULL){
            
//             cout << head -> val << " ";
//             head = head -> next;
//         }
        
//         while(prev != NULL){
            
//             cout << prev -> val << " ";
//             prev = prev -> next;
//         }
        
        
        while(head != NULL && prev!=NULL){
            // cout << head->val << " " << prev -> val << "\n";
            
            if(head -> val != prev -> val)
                return false;
            head = head->next;
            prev = prev ->next;
        }
        
        return true;
    }
};