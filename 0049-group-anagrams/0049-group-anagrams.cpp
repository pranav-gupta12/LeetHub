class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> um;
        for(auto x: s)
        {
            string temp = x;
            sort(x.begin(),x.end());
            um[x].push_back(temp);
        }
        for(auto x: um)
        {
            
ans.push_back(x.second);
            }
        return ans;
    }
};