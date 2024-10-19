class Solution {
public:
    char findKthBit(int n, int k) {
        string temp = "0";
        // if(k==1) return '1';
        while(temp.size()<k){
         int idx = temp.size()-1;
            temp += '1';
            for(idx ; idx>=0;idx--){
                if(temp[idx]=='1'){
                    temp+= '0';
                }
                else
                {
                      temp+= '1';
                }
            }
        }
      return temp[k-1];
    }
};