class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // eff idx = n*row + col
        int eff_i = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int eff_j = row*col-1;
        if(target < matrix[0][0]) return false;
        if(target > matrix[row-1][col-1]) return false;
        while(eff_i <= eff_j){
            int mid = (eff_i + eff_j)>>1;
            int r = mid/col;
            int c = mid % col;
            int key = matrix[r][c];
            if(key==target) return true;
            if(key>target) eff_j = mid-1;
            else
                eff_i = mid+1;
        }
        return false;
    }
};