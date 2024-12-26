class Solution {
public:
    int solve(vector<int>& nums,int idx,int sum, int& target){
        if( idx ==nums.size()) { if(target==sum) return 1;
                                 else return 0;}
        int add = solve(nums,idx+1,sum+nums[idx],target);
          int minus = solve(nums,idx+1,sum-nums[idx],target);
        return add + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,0,0,target); //arr,idx,sum,target
    }
};