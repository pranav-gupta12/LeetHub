class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n,0);
        stack<int> s;
        // s.push(0);
        for(int i=n-1;i>=0;i--)
        {
           int curr = prices[i];
    while(!s.empty() && curr < s.top()) {
        s.pop();
    }
    if (!s.empty()) {
        ans[i] = curr - s.top();
    } else {
        ans[i] = curr; // If the stack is empty, the discount cannot be applied
    }
    s.push(curr);
        }
        return ans;
        
    }
};