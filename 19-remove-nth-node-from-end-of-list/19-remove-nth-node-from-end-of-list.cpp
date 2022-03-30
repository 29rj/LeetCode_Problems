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
    
    int lenNode(ListNode*temp){
        int len = 0;
        
        while(temp!=NULL){
            len++;
            temp = temp ->next;
        }
        
        return len;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len = lenNode(head);
        
        n = len-n-1;//5-1-1 = 3
        
        if(n<0){
            head = head ->next;
            return head;
        }
        
        ListNode *temp = head;
        
        while(n>0){
            temp = temp->next;
            n--;
        }
        
        temp->next = temp->next->next;
        
        return head;
    }
};