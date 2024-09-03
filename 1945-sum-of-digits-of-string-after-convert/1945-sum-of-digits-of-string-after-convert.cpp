class Solution {
public:
    int getLucky(string s, int k) {
        string to_number = "";
        for(char ch : s){
            to_number  += to_string(ch-'a' +1);          
        }
        
        while(k--){
            int temp =0;
          
            for(int i=0;i<to_number.length();i++){
               temp += to_number[i] - '0'  ;
            }
            to_number = to_string(temp);
        }
        return stoi(to_number);
    }
};
