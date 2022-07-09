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
    
    TreeNode* helper(vector<int>&preorder,vector<int>&inorder,int &idx,int left,int right){
        
        if(left > right) 
            return NULL;
        
        int div = left;
        
        while(inorder[div] != preorder[idx]){
            div++;
        }
        
        idx++;
        
        TreeNode *newnode = new TreeNode(inorder[div]);
        newnode -> left = helper(preorder,inorder,idx,left,div-1);
        newnode -> right = helper(preorder,inorder,idx,div+1,right);
        return newnode;

    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        int sz = preorder.size();
        sz--;
        
        return helper(preorder,inorder,idx,0,sz);
    }
};