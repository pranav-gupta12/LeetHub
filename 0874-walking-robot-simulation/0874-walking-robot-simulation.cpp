class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>> directions(4);
        directions[0]= {0,1};
            directions[1]= {1,0};
            directions[2]={0,-1};
            directions[3]= {-1,0};
        int ans = 0;
       unordered_map<int, unordered_set<int>> obstacleMap;

for (const auto& obstacle : obstacles) {
    obstacleMap[obstacle[0]].insert(obstacle[1]);
}                           
        int curr_dir_idx = 0;
                                             int x=0,y=0;
        for(int i=0;i<commands.size();i++){
            if(commands[i] == -2){
                curr_dir_idx = (curr_dir_idx + 3)%4;
            }
            else if ( commands[i]== -1) {
                curr_dir_idx = (curr_dir_idx + 1)%4;
            }
            else 
            {
               int steps = commands[i];
                 pair<int,int> moving_direction = directions[curr_dir_idx];
                
                for(int k=0;k<steps;k++){
                   // [x+moving-direc.first] != y+movingdire.second -- move forward and update distance
                    int new_x = x+moving_direction.first;
                    int new_y = y+moving_direction.second;
                    if(obstacleMap[new_x].find(new_y) == obstacleMap[new_x].end()){
                        x = new_x;
                        y = new_y;
                        ans = max(ans, x*x + y*y);
                    }
                     else break;
                }
            }
        }
    return ans;
    }
};


