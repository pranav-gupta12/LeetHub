class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()> goal.size()) return false;
    if(s.size() < goal.size()) return false;
    s+=s;
    if(s.find(goal) < goal.length()) return true;

    return false;
        
        
    }
};