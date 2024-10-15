class Solution {
public:
    long long minimumSteps(string s) {
        int last_idx = -1;
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') {last_idx=i;
                           break;}
        }
        if(last_idx==-1 || last_idx==0) return 0;
       long long ans = 0; 
    
      for(int i = last_idx-1;i>=0;i--){
          if(s[i]=='1'){
              ans+= last_idx-i;
              last_idx--;
          }
      }
        return ans;
    }
};