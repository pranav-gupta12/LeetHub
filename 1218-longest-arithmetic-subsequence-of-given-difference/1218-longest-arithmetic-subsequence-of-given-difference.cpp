class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int temp = arr[i] - difference;
            int curr=0;
            if(dp[temp]>0) curr = dp[temp];
            dp[arr[i]] = 1+ curr;
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};