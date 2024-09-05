class Solution {
public:
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& marked,int i, int j){
    marked[i][j] = 1;
        for(auto it : dir){
            int new_i = i+it[0];
            int new_j = j+it[1];
           if(new_i>=0 && new_i <marked.size() && new_j>=0 && new_j < marked[0].size() && marked[new_i][new_j]==-1 && grid[new_i][new_j] ==1){
dfs(grid,marked,new_i,new_j);
           }   
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        vector<vector<int>> marked(m,vector<int>(n,-1));
        int tot =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
             if((i == 0 || j == 0 || i == m-1 || j == n-1) && marked[i][j] == -1 && grid[i][j] == 1) {
                    dfs(grid, marked, i, j);
                }
            }
        }
        
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(marked[i][j] !=1 && grid[i][j]==1 ) tot++;
            }
        }
        return tot;
    }
};