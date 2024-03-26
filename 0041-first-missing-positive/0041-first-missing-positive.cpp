class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        if(nums[0]>0)ans++;
        if(nums[0]>0 && nums[0]!=1) return 1;
        for(int i=1;i<nums.size();i++){
            
            if(nums[i]==nums[i-1]) continue;
            if(nums[i]>0){
                ans++;
                if(ans!=nums[i]) return ans;
            }
            // int temp = it;
        }
        return ans+1;
    }
};