class Solution {
public:
    int right(vector<vector<int>>& grid, int i, int j){
        return  grid[i][j] + grid[i][j+1] + grid[i][j+2];
    }
    int down (vector<vector<int>>& grid, int i, int j ){
        return grid[i][j] + grid[i+1][j] + grid[i+2][j];
    }
    bool solve(vector<vector<int>>& grid,int i,int j){
       vector<bool> seen(10, false); // seen[1] to seen[9]

        for (int r = i; r < i + 3; ++r) {
            for (int c = j; c < j + 3; ++c) {
                int num = grid[r][c];
                if (num < 1 || num > 9 || seen[num]) {
                    return false;
                }
                seen[num] = true;
            }
        }

        int diag1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int diag2 = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];
        
        if (diag1 != diag2) return false;

        int sum = diag1;  // This should be the target sum

        return right(grid, i, j) == sum &&
               right(grid, i + 1, j) == sum &&
               right(grid, i + 2, j) == sum &&
               down(grid, i, j) == sum &&
               down(grid, i, j + 1) == sum &&
               down(grid, i, j + 2) == sum;
       
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans=0;
        if(row<3 || col < 3) return ans;
        for(int i=0;i<row-2;i++){
            for(int j=0;j<col-2;j++){
                
                if (solve(grid,i,j)) ans++;
            }
        }
        return ans;
        
    }
};