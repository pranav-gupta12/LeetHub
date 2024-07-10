class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level=0;
        for(auto s : logs){
            string curr = s;
            if(s[0]!= '.'){ level++; continue;}
            if(s.length()==3){
                if(level==0) continue;
                level--;
                continue;
            }
            
        }
        return level;
    }
};