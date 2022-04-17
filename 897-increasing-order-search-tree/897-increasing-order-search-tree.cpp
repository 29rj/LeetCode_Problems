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
    
    vector<int>vec;
    
    void helper(TreeNode* root){
        
        if(!root)
            return;
        
        helper(root->left);
        vec.push_back(root->val);
        helper(root->right);
    }
    
    void makeOrder(TreeNode*&temp , TreeNode *root){
        
        if(!root)
            return;
        
        makeOrder(temp , root -> left);
        
        temp -> right = new TreeNode(root -> val);
        temp = temp -> right;
        
        makeOrder(temp , root -> right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode *ans = new TreeNode();
        TreeNode *temp = ans;
        
        makeOrder(temp,root);
        
        return ans -> right;
        
        /*helper(root);
        
        TreeNode* newRoot = new TreeNode(vec[0]);
        TreeNode * prev = newRoot;
        
        for(int i=1; i < vec.size() ;i++){
            TreeNode* curr = new TreeNode(vec[i]);
            prev->right = curr;
            prev = curr;
        }
        
        return newRoot;*/
    }
};