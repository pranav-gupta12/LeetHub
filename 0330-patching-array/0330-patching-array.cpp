class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i=0;
        long long sum = 1;
        
        int patch=0;
        while(sum<=n){
            sum+= (i<nums.size() && nums[i]<=sum) ? nums[i++] : sum;
            patch++;
        }
        return patch-i;
    }
};