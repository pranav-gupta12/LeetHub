class Solution {
    private:
   int  subarraySum(vector<int>& nums, int k) {
        // int n = nums.size();
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
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)nums[i]=0;
            else
                nums[i]=1;
        }
        return subarraySum(nums,k);
    }
};