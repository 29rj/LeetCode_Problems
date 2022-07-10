class Solution {
public:
    
    void dfs(vector<vector<int>>&image,int sr,int sc,int& color,vector<vector<bool>>&vis,int &inC){
        
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || vis[sr][sc] || image[sr][sc] != inC)
            return;
        
        vis[sr][sc] = true;
        image[sr][sc] = color;
        dfs(image,sr+1,sc,color,vis,inC);
        dfs(image,sr,sc+1,color,vis,inC);
        dfs(image,sr-1,sc,color,vis,inC);
        dfs(image,sr,sc-1,color,vis,inC);
}
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
        int inC = image[sr][sc];

        dfs(image,sr,sc,color,vis,inC);
        
        return image;
    }
};