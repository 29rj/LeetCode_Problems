/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //without using extra space
        
        if(head == NULL)
            return NULL;
        
        Node *temp = head;
        
        while(temp != NULL){
            Node *newnode = new Node(temp->val);
            newnode -> next = temp->next;
            temp -> next = newnode;
            temp = newnode -> next;
        }
        
        //connecting random pointers
        temp = head;
        
        while(temp != NULL && temp->next!=NULL){
            
            if(temp -> random != NULL){
                temp -> next -> random = temp -> random ->next;
            }
            else{
                temp -> next -> random = NULL;
            }
            
            temp = temp -> next -> next;
        }
        
        //removing old pointers
        Node *oldl = head, *newl = head -> next;
        temp = head -> next;
        
        while(oldl && newl){
            
            oldl -> next = oldl -> next -> next;
            
            newl -> next = newl -> next ? newl -> next -> next : newl -> next;
            
            oldl = oldl -> next ;
            newl = newl -> next ;
            
        }
        
        return temp;
        
    }
};