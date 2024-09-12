class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,bool> mapping;
        int ans=0;
            for(char ch : allowed) mapping[ch] = true;
        for(int i=0;i<words.size();i++){
            string temp = words[i];
            bool curr= true;
            for(char ch : temp){
                if(mapping.find(ch) == mapping.end()) curr=false;    
            }
            ans = (curr)? ans+1 : ans;
            
        }
        return ans;
    }
};