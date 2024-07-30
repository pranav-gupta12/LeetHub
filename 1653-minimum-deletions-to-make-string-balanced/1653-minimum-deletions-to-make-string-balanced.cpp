class Solution {
public:
    int minimumDeletions(string s) {
        int count_a=0;
        for(auto &it : s) if(it=='a') count_a++;
        int ans=INT_MAX,count_b=0;
        for(auto it : s){
            if(it=='a') count_a--;
            ans = min(ans, count_a + count_b );
            if(it=='b') count_b++;
            
        }
        return ans;
    }
};