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
    int maxLength(TreeNode* root){
        
        if(!root)
            return 0;
        
        int left = maxLength(root->left);
        
        int right = maxLength(root->right);
        
        return max(left,right)+1;
    }
    
    int helper(TreeNode* root ,int mx,int cn){
         if(!root)
            return 0;
        
        if(!root->left && !root->right && cn==mx)
            return root->val;

        return helper(root->left,mx,cn+1) + helper(root->right,mx,cn+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int mx = maxLength(root);
        return helper(root,mx,1);
    }
};