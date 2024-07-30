class Solution {
public:
    bool checkString(string s) {
        bool flag = false; // saare a b se pehle hai 
        for(auto it: s){
            if(flag == false && it =='b') flag = true; //b aa chuka hai 
             if(flag== true && it=='a') return false;
            
                
            
        }
        return true;
    }
};