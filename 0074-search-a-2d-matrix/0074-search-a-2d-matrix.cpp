class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
                 int m=matrix[0].size();
        int n=matrix.size();
        int i=abs(n-1),j=0;
        while(i >=0 && j<=m-1){
            if(matrix[i][j]==target){
                return true;
            }else if(matrix[i][j] > target){
                i--;
            }else{
                j++;
            }
        }
        return false;
    }
};