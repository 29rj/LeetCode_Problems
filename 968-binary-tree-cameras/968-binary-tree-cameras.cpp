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
    int minCameraCover(TreeNode* root) {
        
        function<void(TreeNode*,TreeNode*, int &,unordered_set<TreeNode*>&)> dfs = [&](TreeNode*root,TreeNode*par, int &cn, unordered_set<TreeNode*>&stk){
            if(!root)
                return;
            
            dfs(root->left,root,cn,stk);
            dfs(root->right,root,cn,stk);
            
            if((par == NULL && stk.find(root) == stk.end()) || (stk.find(root->right) == stk.end()) || (stk.find(root->left) == stk.end()) ){
                cn++;
                
                stk.insert(root);
                stk.insert(par);
                stk.insert(root->left);
                stk.insert(root->right);
            }
            
        };
        
        unordered_set<TreeNode*>stk;
        
        stk.insert(NULL);
        int cn=0;
        TreeNode *par = NULL;
        dfs(root,par,cn,stk);
        
        return cn;
    }
};