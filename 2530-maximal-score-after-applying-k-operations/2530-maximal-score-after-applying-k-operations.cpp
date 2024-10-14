class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long ans=0;
        for(int &it : nums) pq.push(it);
        while(k--){
            int curr = pq.top();
            pq.pop();
            ans+=curr;
            if( curr%3==0) pq.push(curr/3);
            else pq.push(curr/3+1);
        }
        return ans;
    }
};