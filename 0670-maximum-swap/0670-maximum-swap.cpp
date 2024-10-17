class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string compare = s;
        sort(begin(compare),end(compare));
        reverse(begin(compare),end(compare));
        int idx = -1;
        for(int i=0;i<compare.length();i++){
            if(s[i]!=compare[i]){
                idx=i;
                break;
            }   
        }
        if(idx==-1) return num;
        char key =  compare[idx];
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==key){
                swap(s[i],s[idx]);
                return stoi(s);
            }
        }
        return stoi(s);
    }
};