class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
       vector<int> ans;
        for(int i=0;i<row;i++){
            pair<int,int> mini = {INT_MAX,-1};
            for(int j=0;j<col;j++){
                // mini = min(mini,matrix[i][j]);
                if(mini.first> matrix[i][j] ) {
                    mini.first = matrix[i][j];
                    mini.second = j;
                }
            }
           int val = mini.first;
            int idx = mini.second;
            bool possible = true;
            
        for(int k=0;k<row;k++){
            if(matrix[k][idx] > val){
                possible = false;
                break;
            }
            
        }
            if(possible) ans.push_back(val);
        }
       
        return ans;
    }
};