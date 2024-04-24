class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        map<int, int> mpp;
        // mpp[0]= 1;
        int preSum = 0, cnt = 0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            preSum += nums[i];
            int remove = preSum - k;
            cnt+=mpp[remove];
            mpp[preSum]++;
        }
        return cnt; 
    }
};