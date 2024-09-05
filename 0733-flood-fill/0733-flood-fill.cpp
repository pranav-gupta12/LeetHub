class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int temp){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=temp) return;
      image[sr][sc] = color;
     
      dfs(image,sr+1,sc,color,temp);
         dfs(image,sr,sc+1,color,temp);
         dfs(image,sr-1,sc,color,temp);
         dfs(image,sr,sc-1,color,temp);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int temp = image[sr][sc];
        if(temp==color) return image;
        dfs(image,sr,sc,color,temp);
        return image;
    }
};