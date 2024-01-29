class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        for(int i=0;i<row;i++)
        {
            for(int j =i;j<row;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        int e= row-1; int i =0;
        while(i<e)
        {
           for(int r= 0;r<row;r++)
           {
               swap(matrix[r][i],matrix[r][e]);
           }
            i++;e--;
        }
    }
};