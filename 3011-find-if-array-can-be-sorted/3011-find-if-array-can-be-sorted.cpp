class Solution {
public:
    int count(int num){
        int ans=0;
        while(num>0){
            if(num & 1 ==1) ans++;
            num= num>>1;
        }
        return ans;
    }
    bool canSortArray(vector<int>& nums) {
        unordered_map<int,int> setbitcount;
        for(int i=0;i<nums.size();i++){
            setbitcount[i] = count(nums[i]);
        }
        unordered_map<int,int> sortedidx;
        vector<int> arr(nums);
        sort(arr.begin(),arr.end());
        for(int i=0;i<nums.size();i++){
            sortedidx[arr[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            int j = sortedidx[nums[i]];
            int bits = setbitcount[i];
            // i->j same bits
            if(i==j) continue;
            if(i>j){
                for(int k=j;k<i;k++){
                    if(setbitcount[k]!=bits)return false;
                }
            }
            else
            {
                 for(int k=i;k<=j;k++){
                    if(setbitcount[k]!=bits)return false;
                }
            }
        }
        return true;
    }
};