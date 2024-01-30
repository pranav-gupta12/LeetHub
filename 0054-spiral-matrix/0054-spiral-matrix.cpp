class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col=matrix[0].size();
        int startingRow=0; int startingCol = 0;
        int endingRow = row - 1; int endingCol = col-1;
        int count =0;
        vector<int> ans;
        while(count< row*col)
        {
            // left to right in row
            for(int i=  startingCol;i<=endingCol && count<row*col;i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            //top to bottom
            for(int i = startingRow;i<=endingRow && count<row*col;i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            // right to left
            for(int i = endingCol;i>=startingCol && count< row*col;i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            //bottom to top
            for(int i = endingRow;i>=startingRow && count<row*col;i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
                
            }
            startingCol++;
        }
        return ans;
    }
};