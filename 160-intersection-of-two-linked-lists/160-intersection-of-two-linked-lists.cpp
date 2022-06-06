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
    int len(ListNode*node){
        int c=0;
        while(node!=NULL){
            node = node -> next;
            c++;
        }
        
        return c;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = len(headA) , lb = len(headB);
        
        if(la<lb){
            while(la!=lb){
                headB = headB -> next;
                lb--;
            }
        }else{
            while(la!=lb){
                headA = headA->next;
                la--;
            }
        }
        
        while(headA!=NULL && headB!=NULL){
            if(headA == headB){
                return headA;
            }
            headA = headA -> next;
            headB = headB -> next;
        }
        
        return NULL;
    }
};