class Solution {
public:
    // int recursion(vector<int>& satisfaction,int index, int time){
    //     int n = satisfaction.size();
    //     if(index==n) return 0;
    //     int include = satisfaction[index]*(time+1) + recursion(satisfaction,index+1,time+1);
    //     int exclude = 0 + recursion(satisfaction,index+1,time);
    //     return max(include,exclude);
    // }
    int memo(vector<int>& satisfaction, int index, int time,vector<vector<int>>& dp){
         int n = satisfaction.size();
        if(index==n) return 0;
        if(dp[index][time] !=-1) return dp[index][time];
        
        int include = satisfaction[index]*(time+1) + memo(satisfaction,index+1,time+1,dp);
        int exclude = 0 + memo(satisfaction,index+1,time,dp);
        
        return dp[index][time]=max(include,exclude);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
          int n = satisfaction.size();
        // return recursion(satisfaction,0,0);
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1 ));
        return memo(satisfaction, 0, 0,dp);
    }
};