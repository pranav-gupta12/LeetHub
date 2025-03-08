class Solution {
    public int minimumRecolors(String blocks, int k) {
            int i = 0;
        int n = blocks.length();

        int curr = 0 ;
        int j = 0;
        for(j=0;j<k;j++ ){
            if(blocks.charAt(j)=='W') curr++;
        }
        int ans = curr;
        for(j=k;j<n;j++){
            if(blocks.charAt(i)=='W'){
                curr--;
            }
            i++;
            if(blocks.charAt(j)=='W') curr++;
            ans = Math.min(ans,curr);
        }
        return ans;
    }
}