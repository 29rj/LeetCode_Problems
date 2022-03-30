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
    int lenList(ListNode *temp){
        
        int c = 0;
        
        while(temp!=NULL)
        {
            c++;
            temp = temp -> next;
        }
        
        return c;
    }
    
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int la = lenList(headA);
        int lb = lenList(headB);
        
        if(la < lb){
            while(la!=lb){
                lb--;
                if(headA == headB)
                    return headA;
                headB = headB->next;
            }
        } 
        else{
             while(la!=lb){
                la--;
                if(headA == headB)
                    return headA;
                headA = headA->next;
            }
        }
        
        while(headA!=NULL){
            if(headA == headB)
                return headB;
            headA = headA -> next;
            headB = headB -> next;
        }
        
        return NULL;
        
    }
};