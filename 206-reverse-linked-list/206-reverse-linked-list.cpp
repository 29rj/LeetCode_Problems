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
    
    ListNode* helper(ListNode* prev, ListNode *curr){
        
        if(curr == NULL)
            return prev;
        
        ListNode* t = curr -> next;
        curr -> next = prev;
        prev = curr;
        return helper(prev,t);
    }
    
    ListNode* reverseList(ListNode* head) {
        return helper(NULL,head);
    }
};