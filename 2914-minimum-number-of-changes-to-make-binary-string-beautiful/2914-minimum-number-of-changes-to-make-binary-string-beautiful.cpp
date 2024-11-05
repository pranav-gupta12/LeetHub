class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int cnt=0;
        int curr=s[0];
        int ans= 0;
        for(int i=0;i<n;i++){
            if(s[i]==curr){
                cnt++;
            }
            else
            {
                if(cnt%2==0 && n-i %2==0){
                    curr=s[i];
                    cnt=1;
                }
                else
                {
                    ans++;
                    cnt++;
                }
            }
              if(cnt%2==0 && (n-i+1) %2==0){
                    curr=s[i+1];
                    cnt=0;
                }
            
        }
        return ans;
    }
};