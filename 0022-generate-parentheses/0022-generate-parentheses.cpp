class Solution {
public:
    void solve(int i, int j, int n, vector<string>& ans, string& output){
        if(i==n && j==n){ ans.push_back(output); return ;}
        if(i<n) { solve(i+1,j,n,ans,output += '('); output.pop_back();}
                 if(j<i ) { solve(i,j+1,n,ans, output+= ')');output.pop_back();}
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
     solve(0,0,n,ans,output);
        return ans;
    }
};