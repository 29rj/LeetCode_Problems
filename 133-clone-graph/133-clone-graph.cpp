/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*>mp;
    
    void dfs(Node* node, Node* clone,unordered_set<int>&vis){
        
        vis.insert(node->val);
        vector<Node*>now = node->neighbors;
        
        for(int i=0;i<now.size();i++){
            
            Node*newnode;
            if(mp.find(now[i]->val) == mp.end()){
                newnode = new Node(now[i]->val);
                mp[now[i]->val] = newnode;
            }else{
                newnode = mp[now[i]->val];
            }
            
            clone->neighbors.push_back(newnode);
            
            if(vis.find(now[i]->val) == vis.end())
                dfs(now[i],newnode,vis);
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return node;
        Node *clone = new Node(node->val);
        mp[clone->val] = clone;
        
        unordered_set<int>vis;
        
        dfs(node,clone,vis);
        return clone;
    }
};