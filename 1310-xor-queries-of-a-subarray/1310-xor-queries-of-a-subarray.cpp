class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> helper(n);
        int temp = 0;
        for(int i=0;i<n;i++){
            temp = temp ^ arr[i];
            helper[i] = temp;
        }
        vector<int> ans;
        for(int i = 0; i < queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            if(left==0){
                ans.push_back(helper[right]);
            }
            else {
                ans.push_back(helper[right] ^ helper[left-1]);
            }
            
        }
        return ans;
    }
};