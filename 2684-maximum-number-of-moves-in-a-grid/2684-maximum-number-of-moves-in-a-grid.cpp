class Solution {
public:
    vector<pair<int,int>> move = {{-1,1},{0,1},{1,1}};
     int solve(vector<vector<int>>& grid, int x, int y,vector<vector<int>>& dp){
         if(dp[x][y]!=-1) return dp[x][y];
         int ans = 0;
         int curr = grid[x][y];
         for(auto &it:move){
             int new_x = x+it.first;
             int new_y = y+it.second;
             if(new_x<grid.size() && new_x>=0 && new_y< grid[0].size() && grid[new_x][new_y] > curr )
                 ans = max(ans,1+ solve(grid,new_x,new_y,dp));
             
         }
         return dp[x][y]=ans;
         
     }                             
    int maxMoves(vector<vector<int>>& grid) {
        int ans = -1;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col,-1));
        for(int i=0;i<row;i++){
            ans = max(ans,solve(grid,i,0,dp));
        }
        return ans;
    }
};