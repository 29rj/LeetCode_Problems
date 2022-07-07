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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>ans;
        
        while(!q.empty() && q.front()) {
            
            vector<int>temp;
            
            while(q.front() != NULL) {
                
                TreeNode*now = q.front();
                q.pop();
                
                if(now->left)
                    q.push(now->left);
                
                if(now->right)
                    q.push(now->right);
                
                temp.push_back(now->val);
            }
            
            ans.push_back(temp);
            q.pop();
            q.push(NULL);
        }
        
        return ans;
    }
};