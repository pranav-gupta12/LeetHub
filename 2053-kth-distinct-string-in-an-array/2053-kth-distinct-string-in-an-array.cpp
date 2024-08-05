class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> track;
        for(string it: arr) track[it]++;
        // string ans = "";
     for(int i=0;i<arr.size();i++){
         if(track[arr[i]]==1) k--;
         if(k==0) return arr[i];
     }
        
        return "";
    }
};