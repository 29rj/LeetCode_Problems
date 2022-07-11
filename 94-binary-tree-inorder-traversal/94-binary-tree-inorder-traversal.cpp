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
    vector<int> inorderTraversal(TreeNode* root) {
        
        function<void(TreeNode*,vector<int>&)> helper = [&](TreeNode*root,vector<int>&ans){
            if(!root)
                return;
            helper(root->left,ans);
            ans.push_back(root->val);
            helper(root->right,ans);
        };
        
        stack<TreeNode*>stk;
        
        vector<int>ans;
        
        TreeNode*curr = root;
        
        while(curr != NULL || stk.empty() == false){
            
           while(curr!=NULL){
               stk.push(curr);
               curr = curr -> left;
           }
            
            curr = stk.top();
            
            stk.pop();
            
            ans.push_back(curr->val);
            
            curr = curr -> right;
        }
        
        return ans;
    }
};