class Solution {
public:
int MOD = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
int curr_odd=0;
int curr_even=0;
int curr_sum=0;
for(int i=0;i<arr.size();i++){
    curr_sum += arr[i];
    if (curr_sum%2==0) //even
    {
        ans = (ans + curr_odd) % MOD;
        curr_even++;
    }
    else{
        ans = (ans+curr_even+1) % MOD;
        curr_odd++;
    }
// if(arr[i]%2==1) ans = (ans+1)%MOD;
}
return ans;
    }
};