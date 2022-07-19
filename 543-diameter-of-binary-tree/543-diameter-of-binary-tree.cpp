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
    int diameterOfBinaryTree(TreeNode* root) {
        
        function<int (TreeNode*, int &)> recur = [&](TreeNode*root,int &res){
            
            if(root == nullptr)
                return 0;
            
            int left  = recur(root->left,res);
            int right = recur(root->right,res);
            
            int temp = max(left,right);//without considering root
            
            int nowAns = max(temp,left+right);
            
            res = max(res,nowAns);
            
            return temp+1;
        };
        
        int res = INT_MIN;
        
        int ans = recur(root,res);
        
        return res;
    }
};