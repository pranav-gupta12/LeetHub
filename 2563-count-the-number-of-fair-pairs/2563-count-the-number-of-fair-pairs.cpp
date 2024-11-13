class Solution {
public:
//     int highidx(vector<int>& nums, int num){
//         int i = 0;
//         int j = nums.size() - 1;
//         int ans = nums.size();
//         if(num >= nums[ans-1]) return ans;
//         while(i <= j){
//             int mid = (i + j) >> 1;
//             if(nums[mid] >= num){
//                 ans = mid;
//                 j = mid - 1;
//             }
//             else{
//                 i = mid + 1;
//             }
//         }
//         return ans;
//     }
    
//     int lowidx(vector<int>& nums, int num){
//         int i = 0;
//         int j = nums.size() - 1;
//         int ans = -1;
//         if(num > nums[nums.size() - 1]) return -1;
//         while(i <= j){
//             int mid = (i + j) >> 1;
//             if(nums[mid] <= num){
//                 ans = mid;
//                 i = mid + 1;
//             }
//             else{
//                 j = mid - 1;
//             }
//         }
//         return ans;
//     }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(begin(nums), end(nums));
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int low = lower - nums[i];
            int high = upper - nums[i];
            ans += (upper_bound(begin(nums)+i+1,end(nums),high)-begin(nums)-1) - (lower_bound(begin(nums)+i+1,end(nums),low) -begin(nums))+1  ;
        }
        return ans;
    }
};