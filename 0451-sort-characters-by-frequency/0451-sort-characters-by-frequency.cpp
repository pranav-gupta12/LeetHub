class Solution {
public:
    string frequencySort(string s) {
        vector<int> count(128,0);
        for(auto x: s) count[x]++;
        auto cmp = [&](char a, char b)
        {
            if(count[a]==count[b]) return a<b;
            return count[a]>count[b];
        };
        sort(s.begin(),s.end(), cmp);
        return s;
    }
};