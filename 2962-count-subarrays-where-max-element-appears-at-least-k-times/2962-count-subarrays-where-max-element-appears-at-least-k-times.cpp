class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int val = *max_element(nums.begin(),nums.end());
    int l=0,r=0,n=nums.size(),count=0;
        long long ans=0;
        while(r<n){
            if(nums[r]==val)count++;
            while(count>=k){
                ans+=n-r;
                if(nums[l]==val)count--;
                l++;
            }
            r++;
        }
        return ans;
    }
};