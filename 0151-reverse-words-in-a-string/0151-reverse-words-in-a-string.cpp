class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            string temp="";
            while(s[i]!=' ' && i<n)
            {temp+=s[i];
             i++;
            
            }
            if(temp!=""){
            st.push(temp);
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+= st.top();
            ans+= ' ';
            st.pop();
            
        }
        n = ans.length();
        ans.resize(n-1);
        return ans;
    }
};