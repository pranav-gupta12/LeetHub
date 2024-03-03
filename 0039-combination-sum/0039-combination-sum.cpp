class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> output, int index, vector<int> candidates, int target, int sum, int n){
        if(sum>target || index>=n) return; // exceeding case
        if(sum==target) { ans.push_back(output); return;} // base case
        
        // take next element
         solve(ans,output,index+1,candidates,target, sum,n);
        //take current element
        int curr= candidates[index];
        output.push_back(curr);
        // solve(ans,output,index+1,candidates,target, sum+curr,n);
          solve(ans,output,index,candidates,target, sum+curr,n);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int n = candidates.size();
        vector<int> output;
        solve(ans,output,0,candidates,target,0, n);
        return ans;
        
    }
};