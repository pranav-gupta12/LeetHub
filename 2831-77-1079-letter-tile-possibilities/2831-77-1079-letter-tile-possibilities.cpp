class Solution {
    private:
    void solve(vector<int>& count){
        ans++;
        for(int i=0;i<26;i++){
            if(count[i]>0){
                count[i]--;
                solve(count);
                count[i]++;
            }
        }
    }
public:
    int ans = 0;
    int numTilePossibilities(string tiles) {
        vector<int> count(26,0);
        for(auto ch : tiles) count[ch-'A']++;
      
        solve(count);
        return ans-1;
    }
};