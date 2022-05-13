/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(!root)
            return NULL;
        
        queue<Node*>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();//1
            
            vector<Node*>vec;
            
            while(n--){
                
                Node *curr = q.front();//1
                q.pop();
                
                if(curr->left){
                    q.push(curr->left);
                    vec.push_back(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                    vec.push_back(curr->right);
                }
            }
            
            for(int i=0;i+1<vec.size();i++){
                vec[i]->next = vec[i+1];
            }
        }
        
        return root;
    }
};