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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        
          if(!root)
            return ans;
        
        queue<TreeNode*>q;
        q.push(root);
        
        int lv = 0;
        
        while(!q.empty()){
            
            int sz = q.size();
            vector<int>vec(sz);
            
            int i=0,add=1;
            
            if(lv % 2 == 1){
                add = -1;
                i=sz-1;
            }
            
            while(sz > 0){
                TreeNode*temp = q.front();
                q.pop();
                
                vec[i] = temp->val;
                i += add;
                
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
                
                sz--;
            }
            
            ans.push_back(vec);
            
            lv++;   
        }
        
        return ans;
    }
};