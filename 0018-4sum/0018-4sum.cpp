class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      
         vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int k=j+1,l=n-1;
          
            while(k<l)
            {
                 long long sum = nums[i] ;
                sum+=nums[j];
                sum+=nums[k];
                sum+=nums[l];
                if(sum==target)
                   {
                       vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    while(k<l && nums[l]==nums[l-1]) l--;
                      while(k<l && nums[k]==nums[k+1])  k++;
                    l--;
                    k++;
                    
                   }
               else if ( sum<target)
                   k++;
                else
                    l--;
            }
                while(j<n-2 && nums[j]==nums[j+1]) j++;
                    
            }
                    while(i<n-3 && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};