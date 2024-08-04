class Solution {
public:
    const int MOD = 1e9+7;
    typedef pair<int,int> P;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P,vector<P>,greater<P>> pq;
        
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        int ans=0;
       for(int count=1;count<=right;count++ ){
           P top = pq.top();
           pq.pop();
           int sum = top.first;
           int idx = top.second;
           if(count>=left) ans = (ans+sum) % MOD;
           idx+=1;
           if(idx<n){
               pq.push({sum+=nums[idx], idx});
           }
       }
        return ans;
    }
};