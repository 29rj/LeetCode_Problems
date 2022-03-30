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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp1 = l1 , *temp2 = l2 , *prev1 = NULL;
        
        int rem = 0;
        
        while(temp1 != NULL && temp2 != NULL ){
            
            rem += (temp1->val)+(temp2->val);
            
            temp1->val = rem%10;
            
            rem = rem/10;
            
            prev1 = temp1;
            temp1 = temp1 -> next;
            
            temp2 = temp2 -> next;
        }
        
        
        if(temp1 != NULL){
            
             while(temp1!=NULL){
                prev1 = temp1;
                rem += temp1->val;
                temp1->val = rem%10;
                rem /= 10;
                temp1 = temp1->next;
             }
            
            if(rem != 0){
                ListNode *newnode = new ListNode(rem);
                prev1->next= newnode;
            }    
        }
        
        else{
            prev1->next = temp2;
            
            while(temp2!=NULL){
                
                prev1 = temp2;
                rem += temp2 -> val;
                temp2 -> val = rem%10;
                rem /= 10;
                temp2 = temp2 ->next;
            }
            
            if(rem != 0){
                ListNode *newnode = new ListNode(rem);
                prev1->next= newnode;
            }
        }
        
        return l1;
    }
};