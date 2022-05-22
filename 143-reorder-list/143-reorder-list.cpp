// class Solution {

// public : ListNode* getMid(ListNode* head)
// {
//     ListNode* slow = head;
//     ListNode* fast = head;
    
//     while(fast && fast->next)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     return slow;
// }
    
// public : ListNode* reverseList(ListNode* head)
// {
//     ListNode* curr = head;
//     ListNode* prev = NULL;
//     ListNode* temp;
    
//     while(curr)
//     {
//         temp = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = temp;
//     }
//     return prev;
// }

// public:
//     void reorderList(ListNode* head) {
        
//         ListNode* mid = getMid(head);
//         ListNode* endList = mid;
        
//         endList->next = NULL;
//         ListNode* reversedHead = reverseList(mid);
//         ListNode* p1 = head;
//         ListNode* p2 = reversedHead;
        
//         while(p1 && p2 && p1->next && p2->next)
//         {
//             ListNode* temp1 = p1->next;
//             ListNode* temp2 = p2->next;
//             p1->next = reversedHead;
//             p2->next = temp1;
//             p1 = temp1;
//             p2 = temp2;
//         }
//     }
// };


class Solution {
    
public : ListNode* reverseList(ListNode* head)
{
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* temp;
    
    while(curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
    
public : void mergeList(ListNode* l1, ListNode* l2)
{
    while(1){
        ListNode* l1Next=l1->next;
        ListNode* l2Next=l2->next;
        l1->next=l2;
        
        if(l1Next==NULL)
            break;
        
        l2->next=l1Next;
        l1=l1Next;
        l2=l2Next;
        }
}

public:
    void reorderList(ListNode* head) {
        
        if(!head || !head->next)
        {
            return;
        }
        ListNode* prev; //tail of first half
        ListNode* slow = head; 
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        ListNode* p2 = reverseList(slow);
        
        ListNode* p1 = head;        
        
        mergeList(p1,p2);
        
    }
};
