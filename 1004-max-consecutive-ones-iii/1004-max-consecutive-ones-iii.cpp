class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int ans = 0;
        int maxi = INT_MIN;
        while(j<nums.size()){
            if(nums[j]==1){ ans++;j++;}
            else if(nums[j]==0 && k>0){
                ans++;
                k--;
                j++;
                
            }
            else
            {
                
                while(k==0){
                if(nums[i]==0){
                    k++;
                    i++;
                    ans--;
                }
                    else
                    {
                        i++;
                        ans--;
                    }
               }
                
            }
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};