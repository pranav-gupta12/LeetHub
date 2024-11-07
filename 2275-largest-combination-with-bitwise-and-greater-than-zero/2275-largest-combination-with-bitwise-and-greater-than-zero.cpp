class Solution {
public:
    int largestCombination(vector<int>& candidates) {
                int ans = -1;
        for(int i = 0;i < 24; i++){
            int res = 0;
            for(int j = 0;j < candidates.size(); j++){
                if (candidates[j] & (1 << i)) {
                    res++;
                }
            }
            ans = max(ans,res);
        }
        return ans;
    }
};