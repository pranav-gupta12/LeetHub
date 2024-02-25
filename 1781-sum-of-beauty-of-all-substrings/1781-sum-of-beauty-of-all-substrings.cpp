class Solution {
public:
    int beauty(vector<int> array){
        int mf=0;
        int lf=INT_MAX;
        for(int x : array){
            mf = max(mf,x);
            if(x>0) lf = min(lf,x);
        }
        return ( mf-lf);
    }
    int beautySum(string s) {
         int res = 0;
        for(int i=0;i<s.length();i++){
            vector<int> count(26,0);
            for(int j=i;j<s.length();j++){
                count[s[j]- 'a']++;
                res+= beauty(count);
            }
        }
        return res;
    }
};