class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> dp[nums.size()];
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int diff = nums[i] - nums[j];
                int cnt = 1;
                if(dp[j].count(diff)) cnt = dp[j][diff];
                dp[i][diff] = 1+cnt;
                ans = max(ans,dp[i][diff]);
            }
        }
        return ans;
    }
};