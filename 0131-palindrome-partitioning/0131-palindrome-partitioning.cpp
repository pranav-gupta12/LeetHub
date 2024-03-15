class Solution {
public:
    void solve(string s, int index, vector<vector<string>>& ans, vector<string>& curr){
        if(index>=s.length()) {
            ans.push_back(curr);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                curr.push_back(s.substr(index,i-index+1));
                solve(s,i+1,ans,curr);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
          vector<vector<string>> ans;
        vector<string> curr;
        solve(s,0,ans,curr);
        return ans;
    }
};