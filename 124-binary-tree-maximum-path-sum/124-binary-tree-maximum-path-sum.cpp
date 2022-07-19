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
    
    int helper(TreeNode*root,int &ans){
        if(!root)
            return 0;
        
        int left = helper(root->left,ans);
        int right = helper(root->right,ans);
        
        if(left < 0 && right < 0)
            left = 0;
        
        int temp = root-> val + max(left,right); 
        
        int currAns = max(temp,left+right+root->val);//left and right + root
        
        ans = max(ans,currAns);
        
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        
        int ans = INT_MIN;
        helper(root,ans);
        return ans;
    }
};