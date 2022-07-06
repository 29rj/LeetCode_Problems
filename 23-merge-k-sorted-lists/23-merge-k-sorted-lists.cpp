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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        auto takeOut = [&](vector<ListNode*>lists){
            
            int mn = INT_MAX;
            int in = -1;
            
            for(int i=0;i<lists.size();i++){
                // cout << lists[i] << " ";
                if(lists[i]){
                    if(lists[i]->val < mn){
                        mn = lists[i]->val;
                        in = i;
                    }
                }
            }
            
            return in;
        };
        
        ListNode* newHead = NULL,*temp = NULL;
        
        int in = 0;
        
        while(in != -1){
            
            in = takeOut(lists);
            
            if(in == -1)
                break;
            
            // cout << lists[in] << " ";
            
            if(newHead == NULL){
                newHead = lists[in];
                temp = newHead;
                lists[in]  = lists[in] -> next;
            }else{
                temp -> next = lists[in];
                temp = temp -> next;
                lists[in]  = lists[in] -> next;
            }
        }
        
        return newHead;
    }
};