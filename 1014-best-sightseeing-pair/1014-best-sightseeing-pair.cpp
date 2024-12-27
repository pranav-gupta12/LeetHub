class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        map<int,int> map;
        for(int i=1;i<values.size();i++){
            map[values[i] - i]++;
        }
        int ans = INT_MIN;
        for(int i=0; i < values.size()-1;i++){
               if(i>0){
              map[values[i]-i]--;
              if(map[values[i]-i]==0) map.erase(values[i]-i);
          }
            ans = max(ans, values[i]+i + map.rbegin()->first);
       
        }
        return ans;
    }
};