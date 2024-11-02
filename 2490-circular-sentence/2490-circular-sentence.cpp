class Solution {
public:
    bool isCircularSentence(string s) {
        int n = s.size();
        // int i= 0;
        if(s[n-1]!=s[0]) return false;
      for(int i=0;i<n-1;i++){
          if(s[i+1]==' ' && s[i]!=s[i+2]) return false;
      }
        return true;
    }
};