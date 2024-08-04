class Solution {
public:
    int missingInteger(vector<int>& nums) {
          int pss = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                pss += nums[i];
            } else {
                break;
            }
        }
        unordered_set<int> numset(nums.begin(),nums.end());
      
      while (numset.count(pss)) ++pss;
        return pss;
    }
};