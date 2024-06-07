class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
         int n = nums.size();
        stack<int> ls, lb;
        vector<int> leftsmall(n, -1), rightsmall(n, n);
        vector<int> leftbig(n, -1), rightbig(n, n);
        
        // Calculate left boundaries for smaller and bigger elements
        for (int i = 0; i < n; ++i) {
            // For smaller elements
            while (!ls.empty() && nums[ls.top()] >= nums[i]) {
                ls.pop();
            }
            if (!ls.empty()) {
                leftsmall[i] = ls.top();
            }
            ls.push(i);
            
            // For bigger elements
            while (!lb.empty() && nums[lb.top()] <= nums[i]) {
                lb.pop();
            }
            if (!lb.empty()) {
                leftbig[i] = lb.top();
            }
            lb.push(i);
        }

        // Clear stacks
        while (!ls.empty()) ls.pop();
        while (!lb.empty()) lb.pop();
        
        // Calculate right boundaries for smaller and bigger elements
        for (int i = n - 1; i >= 0; --i) {
            // For smaller elements
            while (!ls.empty() && nums[ls.top()] > nums[i]) {  // Note: strictly greater for right bounds
                ls.pop();
            }
            if (!ls.empty()) {
                rightsmall[i] = ls.top();
            }
            ls.push(i);
            
            // For bigger elements
            while (!lb.empty() && nums[lb.top()] < nums[i]) {  // Note: strictly less for right bounds
                lb.pop();
            }
            if (!lb.empty()) {
                rightbig[i] = lb.top();
            }
            lb.push(i);
        }

        long long ans = 0;

        // Calculate the sum of ranges
        for (int i = 0; i < n; ++i) {
            long long maxContribution = (long long)(i - leftbig[i]) * (rightbig[i] - i) * nums[i];
            long long minContribution = (long long)(i - leftsmall[i]) * (rightsmall[i] - i) * nums[i];
            ans += maxContribution - minContribution;
        }

        return ans;
    }
};