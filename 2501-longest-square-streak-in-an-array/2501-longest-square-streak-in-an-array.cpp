class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
         int ans=1;
        int maxi = nums.back();
        for(int i=0;i<nums.size();i++){
          long long sq = static_cast<long long>(nums[i]) * nums[i];
            if(mp.count(nums[i])){
                if(sq >maxi){
                    ans = max(ans,mp[nums[i]]+1);
                    continue;
                }
                else
                {
                    mp[nums[i]*nums[i]] = mp[nums[i]]+1;
                     ans = max(ans,mp[nums[i]]+1);                   
                }
                
            }
            else
            {
                
                 if(sq >maxi){
                   continue;
                }
                else
                {
                    mp[nums[i]*nums[i]] = 1;                  
                }
            }
        }
        return (ans==1)? -1 : ans;
    }
};