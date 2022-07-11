/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        
        if(!root)
            return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        ans.push_back(root->val);
        
        while(!q.empty() && q.front() ){
            
           TreeNode*prev=NULL;
            
            while(q.front() != NULL){
                
                TreeNode*temp = q.front();
                q.pop();
                
                if(temp -> left){
                    q.push(temp->left);
                    prev =temp->left;
                }
                
                if(temp -> right){
                    q.push(temp->right);
                    prev = temp->right;
                }
            }
            
            if(prev)
                ans.push_back(prev->val);
            
            q.pop();
            
            q.push(NULL);
        }
        
        return ans;
    }
};