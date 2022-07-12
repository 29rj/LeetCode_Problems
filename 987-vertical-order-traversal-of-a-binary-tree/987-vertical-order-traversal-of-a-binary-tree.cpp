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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        queue<pair<TreeNode*,int>>q;
        
        q.push({root,0});
        q.push({NULL,0});
        
        map<int,vector<pair<int,int>>>mp;
        
        vector<vector<int>>ans;
        
        int lv = 0;
        
        while(!q.empty() && q.front().first){
            
            while(q.front().first != NULL){
                
                auto it = q.front();
                q.pop();
                
                TreeNode* temp = it.first;
                
                int num = it.second;
            
                mp[num].push_back({lv,temp->val});
                
                // cout << num << " " << temp->val << "\n";
            
                if(temp->left)
                    q.push({temp->left,num-1});
                
                if(temp->right)
                    q.push({temp->right,num+1});
            }
            
            lv++;
            
            q.pop();
            q.push({NULL,0});
        }
        
        for(auto&it:mp){
            sort(it.second.begin(),it.second.end());
            vector<int>temp;
            
            for(int i=0;i<it.second.size();i++)
                temp.push_back(it.second[i].second);
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};