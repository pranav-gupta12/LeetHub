class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> track1;
        for(string it: words1) track1[it]++;
           unordered_map<string,int> track2;
        for(string it: words2) track2[it]++;
        int ans=0;
        for(auto it: track1)
            if(it.second==1 && track2[it.first]== 1  ) ans++;
        return ans;
    }
};