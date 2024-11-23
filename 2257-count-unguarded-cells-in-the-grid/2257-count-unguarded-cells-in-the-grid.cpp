class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(m,vector<int>(n,0));
        for(auto v : guards){
            mat[v[0]][v[1]] = -1;
        }
        for(auto v : walls) mat[v[0]][v[1]] =1;
        for(auto v : guards){
            int x = v[0];
            int y = v[1];
            x--;
            while(x>=0 && (mat[x][y]==0 || mat[x][y]==2)){
                mat[x][y]=2;
                x--;
            }
            x = v[0];
            x++;
            while(x<m && (mat[x][y]==0 || mat[x][y]==2)){
                mat[x][y]=2;
                x++;
            }
            x =v[0];
            y--;
            while(y>=0  && (mat[x][y]==0 || mat[x][y]==2)){
                mat[x][y]=2;
                y--;
            }
            y = v[1];
            y++;
            while(y<n &&(mat[x][y]==0 || mat[x][y]==2)){
                mat[x][y]=2;
                y++;
            }
            
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) ans++;
            }
        }
        return ans;
    }
};