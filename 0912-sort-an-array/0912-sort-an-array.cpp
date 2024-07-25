class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int , vector<int>, greater<int>> minheap;
        for(auto it : nums) minheap.push(it);
        for(int i=0;i<nums.size();i++){
            nums[i] = minheap.top();
            minheap.pop();
        }
        return nums;
    }
};