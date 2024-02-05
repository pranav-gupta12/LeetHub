class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map <char,int> count;
        for(int i=0; i<s.size();i++)
        {
            count[s[i]]++;
        }
        int ans= -1;
       for(int i=0; i<s.size();i++)
        {
           if(count[s[i]]==1) return i;
        }
        return ans;
    }
};