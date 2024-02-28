class Solution {
public:
    bool Binary_Search(vector<vector<int>>& matrix, int target, int row, int col){
        int low = 0, high  = col-1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(matrix[row][mid]== target) return true;
            else if(matrix[row][mid]< target) low = mid+1;
            else high = mid-1;}
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0;
        while(row<= rows-1){
            if(matrix[row][0]<=target && matrix[row][cols-1] >=target ) return Binary_Search(matrix,target,row,cols);
            row++;
        }
        return false;
    }
};