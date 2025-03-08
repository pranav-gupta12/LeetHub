class Solution {
public:
    int minimumRecolors(string blocks, int k) {
    
        int i = 0;
        int n = blocks.length();
        int ans = INT_MAX;
        int curr = 0 ;
        int j = 0;
        for(j;j<k;j++ ){
            if(blocks[j]=='W') curr++;
        }
        ans = min(ans,curr);
        for(j;j<n;j++){
            if(blocks[i]=='W'){
                curr--;
            }
            i++;
            if(blocks[j]=='W') curr++;
            ans = min(ans,curr);
        }
        return ans;
    }
};