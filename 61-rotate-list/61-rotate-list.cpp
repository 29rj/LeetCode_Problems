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
    int lenList(ListNode *head) {
        
        int c = 0;
        
        while(head!=NULL) {
            head = head -> next;
            c++;
        }
        
        return c;
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)
            return NULL;
        
        int len = lenList(head);
        
        k = k % len;
        
        if(k == 0)
            return head;
        
        ListNode *temp = head, *last = head;
        
        k = len - k - 1;
        
        while(last->next!=NULL){
            
            last = last -> next;
            
            if(k!=0){
                temp = temp -> next;
                k--;
            }
        }
        
        
        last -> next = head;
        head = temp -> next;
        temp -> next = NULL;
        
        return head;
       
    }
};