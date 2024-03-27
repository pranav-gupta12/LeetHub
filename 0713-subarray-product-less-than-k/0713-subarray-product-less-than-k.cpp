class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0 || k==1) return 0;
        int l=0,r=0,ans=0,product=1;
        while(r<nums.size()){
            product *= nums[r++];
            while(product >=k && l<=r){
                product /= nums[l++];
            }
            ans += r-l;
        }
        return ans;
    }
};