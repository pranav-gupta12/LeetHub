class Solution {
public:
   int minimum(vector<int> &mp){
        int k = INT_MAX;
        for(auto it : mp){
            if(it<=k && it>0)
                k = it;
        }
        return k;
    }
    int maximum(vector<int> &mp){
        int k = INT_MIN;
        for(auto it : mp){
            if(it>=k)
                k = it;
        }
        return k;
    }
    int beautySum(string s) {
        int sum = 0;
        for(int i = 0; i<s.size();i++){
            vector<int> mp(26,0);
            for(int j=i; j<s.size();j++){
                mp[s[j]-'a']++;
                int mx = maximum(mp);
                int mn = minimum(mp);
                sum += mx - mn;
            }
        }
        return sum;
    
        
    }
};