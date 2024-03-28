class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0,r=0,ans=0;
        unordered_map<int,int> count;
        while(r<nums.size()){
            count[nums[r]]++;
            if(count[nums[r]]>k){
                while(count[nums[r]]>k) count[nums[l++]]--;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};