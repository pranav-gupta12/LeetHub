class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int i = 0;
        int j = 1;
        int n = nums.size();
        if(n<=1) return true;
        while(j<n){
            if(nums[i] %2  == nums[j] %2) return false;
            i++;
            j++;
        }
        return true;
    }
};