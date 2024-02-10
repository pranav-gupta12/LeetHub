class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1,ans=INT_MAX;
        if(e==0) return nums[0];
        while(s<e)
        {
            int mid = (s+e)>>1;
            ans = min(ans,nums[mid]);
            ans = min(ans,nums[s]);
            ans = min(ans, nums[e]);
            if(nums[mid]>nums[s]) s = mid;
            else e = mid;
        }
        return ans;
    }
};