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
    
    int heightTree(TreeNode *root)
    {
         if(root==NULL) {
            return 0;
        }
        
//         int left=0,right=0;
    
//         if(root->left != NULL) {
            
//             left = heightTree(root->left) + 1;
//         }
        
//         if(root->right != NULL) {
            
//             right = heightTree(root->right) + 1;
//         }
        
        return max(heightTree(root->left),heightTree(root->right))+1;
    }
    
    int maxDepth(TreeNode* root) {
       
        if(root!=NULL) {
            return heightTree(root);
        }
        
         return 0;
    }
        
       
};