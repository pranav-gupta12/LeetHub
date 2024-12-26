class Solution {
public:
    int solve(vector<int>& nums,int idx,int sum, int& target, map<pair<int,int>, int>& memo){
        if( idx ==nums.size()) { if(target==sum) return 1;
                                 else return 0;}
        pair<int,int> p = {idx,sum};
        if(memo.find(p)!=memo.end()) return memo[{idx,sum}];
        int add = solve(nums,idx+1,sum+nums[idx],target,memo);
          int minus = solve(nums,idx+1,sum-nums[idx],target,memo);
        return memo[p] = add+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>, int> memo;
      return solve(nums, 0, 0, target,memo);
    }
};