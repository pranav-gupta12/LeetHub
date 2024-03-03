class Solution {
    
public:
    void solve( int target,vector<int>& arr, vector<vector<int>> &ans, vector<int> &output, int index){
        if(target==0){
            ans.push_back(output);
            return;
        }
        for(int i=index;i<arr.size();i++){
            if(arr[i]>target) break;
            if(i>index && arr[i-1]==arr[i]) continue;
            output.push_back(arr[i]);
            solve(target-arr[i],arr,ans,output,i+1);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        vector<int> output;
        solve(target,arr,ans,output,0);
        return ans;
    }
};