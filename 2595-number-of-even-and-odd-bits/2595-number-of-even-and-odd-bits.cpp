class Solution {
public:
    vector<int> evenOddBit(int n) {
        int odd=0;
        int even=0;
        int i=0;
        while(n){
            if(n %2==1){
                if(i%2==0) even++;
                    else odd++;
            }
            i++;
            n= n/2;
            
        }
        return {even,odd};
    }
};