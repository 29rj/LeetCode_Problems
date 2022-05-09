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
    
    pair<int,int> helper(TreeNode *root) {
        
        if(root == nullptr) {
            pair<int,int>pr{0,0};
            return pr;
        }
        
        pair<int,int>left = helper(root->left);
        
        pair<int,int>right = helper(root->right);
        
pair<int,int>pr{ root->val+left.second+right.second,max(left.first,left.second)+max(right.first,right.second) };
        
        return pr;  
    }
    
    
    int rob(TreeNode* root) {
        pair<int,int>pr = helper(root);
        return max(pr.first,pr.second);
    }
};