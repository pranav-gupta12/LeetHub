class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long,int> mp;
        for(int i=0;i<nums.size()-1 ;i++){
            long long sum = nums[i];
            for(int j=i+1;j<nums.size();j++){
                sum *= nums[j];
                mp[sum]++;
                sum = nums[i];
            }
        }
        int ans = 0;
        for(auto it: mp){
            int num = it.second;
            if(num>1){
                ans += 8*(num)*(num-1)/2;
            }
        }
        return ans;
    }
};