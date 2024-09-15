class Solution {
public:
    vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    typedef pair<pair<int,int>,int> p;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<p> que;
        // co-ordinate , level
        int n  = grid.size();
        if(grid[0][0] !=0 || grid[n-1][n-1]!=0) return -1;
        que.push({{0,0},1});
        grid[0][0] = 1;
        while(!que.empty()){
            p curr = que.front();
            que.pop();
          
            int level = curr.second;
            int x =  curr.first.first;
            int y = curr.first.second;
           
            if(x==n-1 && y==n-1) return level;
            for(auto &it : dir){
                int _x = x + it[0];
                int _y = y + it[1];
                if( _x>=0 && _x<n && _y>=0 &&  _y<n && grid[_x][_y]==0) {
                    que.push({{_x,_y},level+1});
                     grid[_x][_y]=1;
                }
            }
        }
        return -1;
    }
};