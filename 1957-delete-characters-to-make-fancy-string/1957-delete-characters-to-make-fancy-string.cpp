class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string ans= "";
        char ch = s[0];
        int cnt=1;
        ans += ch;
        for(int i=1;i<n;i++){
            if(ch==s[i] && cnt==2) continue;
            else if (ch==s[i] && cnt<2) {ans+=ch;
                                         cnt++;}
            else if(ch!=s[i]){
                ch = s[i];
                cnt=1;
                ans+=ch;
            }
        }
    return ans;
    }
    
};