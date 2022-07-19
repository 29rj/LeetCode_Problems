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
    TreeNode* path(TreeNode*root,TreeNode*dest,vector<TreeNode*>&vec){
        if(root == NULL)
            return NULL;
        
        if(root == dest){
            vec.push_back(root);
            return root;
        }
        
        TreeNode* left = path(root->left,dest,vec);
        TreeNode* right = path(root->right,dest,vec);
        
        if(left || right){
            vec.push_back(root);
            return root;
        }
        
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>vec1,vec2;
        
        path(root,p,vec1);
        path(root,q,vec2);
        
        reverse(vec1.begin(),vec1.end());
        
        reverse(vec2.begin(),vec2.end());
        
//         for(auto&it:vec1){
//             cout << it->val << " ";
//         }
        
//         cout << "\n";
        
//         for(auto&it:vec2){
//             cout << it->val << " ";
//         }
        
        for(int i=1;i<min(vec1.size(),vec2.size());i++){
            
            if(vec1[i] != vec2[i]){
                return vec1[i-1];
            }
        }
        
        if(vec1.size() < vec2.size()){
            return vec1.back();
        }else
            return vec2.back();
        
        return root;
    }
};