class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> minrow(row,0);
        unordered_set<int> maxcol;
        for(int i=0;i<row;i++){
            int mini = INT_MAX;
            for(int j=0;j<col;j++){
                mini = min(mini,matrix[i][j]);
            }
            minrow.push_back(mini);
        }
        for(int i=0;i<col;i++){
            int maxi = INT_MIN;
            for(int j=0;j<row;j++){
                maxi = max(maxi,matrix[j][i]);

            }
maxcol.insert(maxi);
        }
        vector<int> ans;
        for(auto it : minrow){
            if(maxcol.count(it)) ans.push_back(it);
        }
        return ans;
    }
};