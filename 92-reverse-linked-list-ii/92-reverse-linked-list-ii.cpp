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
    ListNode* reverseBetween(ListNode* root, int left, int right) {
        if(root == NULL || root -> next == NULL)
            return root;
        
        ListNode*prevLeft = NULL,*nextRight = NULL;
        ListNode*temp = root;
        
        int i=1;
        while(temp && i < left){
            prevLeft = temp;
            temp = temp -> next;
            i++;
        }
        
        // cout << prevLeft->val << " ";
        
        if(temp == NULL)
            return root;
        
        ListNode *curr = temp->next,*prev = temp;
        
        i=right-left;
        
        while(prev && i > 0){
            ListNode *now = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = now;
            i--;
        }
        
        if(prevLeft)
            prevLeft -> next = prev;
        else
            root = prev;
        temp -> next = curr;
        return root;
    }
};