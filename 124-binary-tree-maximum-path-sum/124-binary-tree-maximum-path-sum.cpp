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
    int maxPathSum(TreeNode* root) {
        function<int(TreeNode*,int &)> recur = [&](TreeNode*root,int &res){
            if(root == nullptr)
                return 0;
            
            int left = recur(root->left,res);
            int right = recur(root->right,res);
            
            if(left < 0 && right < 0)
                left = 0;
                
            int temp = root->val + max(left,right);
            
            int currAns = max(temp,left+right+root->val);
            
            res = max(res,currAns);
            
            return temp;
        };
        
        int res = INT_MIN;
        
        recur(root,res);
        
        return res;
    }
};