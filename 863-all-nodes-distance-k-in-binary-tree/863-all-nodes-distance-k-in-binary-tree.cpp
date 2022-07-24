/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        //Multisource bfs from target node
        
        //Step 1: Take out parent of every node
        
        unordered_map<TreeNode*,TreeNode*>mp;
        
        queue<TreeNode*>q;
        
        q.push(root);
        mp[root] = NULL;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--) {
                
                TreeNode* pr = q.front();
                q.pop();
                
                if(pr->left){
                    mp[pr->left] = pr;
                    q.push(pr->left);
                }
                
                if(pr->right){
                    mp[pr->right] = pr;
                    q.push(pr->right);
                }
            }
        }
        
//         for(auto&it:mp){
//             if(it.first){
//                 cout << it.first->val << " ";
//             }
            
//             if(it.second){
//                 cout << it.second->val << "\n";
//             }
            
            
//         }
        
        vector<int>ans;
        
        queue<TreeNode*>empty;
        
        swap(empty,q);
        
        // cout << q.size() << " ";
        
        q.push(target);
        
        int lv = 0;
        
        unordered_map<TreeNode*, bool> visited;
        
        visited[target]=true;
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                
                TreeNode* now = q.front();
                q.pop();
                
                if(lv == k)
                    ans.push_back(now->val);
                
                //left
                if(now->left and visited.find(now->left) == visited.end()){
                    visited[now->left] = true;
                    q.push(now->left);
                }
                
                //right
                if(now->right and visited.find(now->right) == visited.end()){
                    visited[now->right] = true;
                    q.push(now->right);
                }
                
                //parent
                if(mp[now] and visited.find(mp[now]) == visited.end()){
                    visited[mp[now]] = true;
                    q.push(mp[now]);
                }
            }
            
            lv++;
        }
        
        return ans;
        
    }
};