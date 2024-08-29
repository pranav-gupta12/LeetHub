class Solution {
public:
    void dfs(vector<vector<int>>& stones,vector<bool>& visited, int index ){
        visited[index] = true;
        int r = stones[index][0];
        int c = stones[index][1];
        for(int i = 0 ; i< stones.size(); i++){
        if(visited[i]==false && (r == stones[i][0] || c == stones[i][1])){
            visited[i] = true;
            dfs(stones,visited,i);
        }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n =stones.size();
        vector<bool> visited(n,false);
        int group = 0;
        for(int i = 0; i < n ; i++){
            if(visited[i] == false){
                dfs(stones, visited, i);
                group++;
            }
        }
        return n - group;
    }
};