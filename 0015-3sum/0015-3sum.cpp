class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; 
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int j=i+1,k=n-1;
            int target=-nums[i];
            while(j<k)
            {
                if(nums[j]+nums[k]<target)
                    j++;
                else if(nums[j]+nums[k]>target)
                    k--;
                else
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==nums[j+1])
                        j++;
                    while(j<k && nums[k]==nums[k-1])
                        k--;
                    j++;
                    k--;
                }
            }
            while(i+1<n && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};