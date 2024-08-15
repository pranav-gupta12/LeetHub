class Solution {
    private:
      static bool sortcol( vector<int> v1, const vector<int> v2)
{
          if(v1[0]==v2[0]) return v1[1] > v2[1];
    return v1[0] < v2[0];
}
public:
    // bool sortcol(const vector<int>& v1,const vector<int>& v2) {return v1[0]<v2[0];}
 
    int binarydp(vector<vector<int>>& envelopes){
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(envelopes[i][1] > ans.back()) ans.push_back(envelopes[i][1]);
            else{
                int index = lower_bound(ans.begin(),ans.end(), envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),sortcol);
        return binarydp(envelopes);
        
    }
};