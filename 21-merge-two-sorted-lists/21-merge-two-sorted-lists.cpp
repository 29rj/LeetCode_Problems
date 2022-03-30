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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1)
            return list2;
        
        if(!list2)
            return list1;
        
        ListNode *l,*h,*temp=NULL,*head = NULL;
        
        if(list1->val < list2->val){
            l = list1;
            h = list2;
            head = l;
        }
        else{
            l = list2;
            h = list1;
            head = l;
        }
        
        while(l!=NULL){
            
            if(l->val > h->val){
                temp->next = h;
                ListNode *swap = l;
                l = h;
                h = swap;
                temp = NULL;
            }
            else{
                temp = l;
                l = l->next;
            }
        }
        temp->next = h;
        return head;
        
    }
};