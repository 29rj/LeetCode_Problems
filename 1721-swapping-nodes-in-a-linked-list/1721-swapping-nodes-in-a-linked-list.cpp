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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode*swap1=head,*swap2=head,*temp;
        
        k--;
        while(k--){
            swap1 = swap1 -> next;
        }
        
        temp = swap1;
        swap2 = head;
        
        while(temp->next != NULL){
            
            temp = temp -> next;
            swap2 = swap2 -> next;
            
        }
        
        int val = swap1 -> val;
        swap1 -> val = swap2 -> val;
        swap2 -> val = val;
        return head;
    }
};