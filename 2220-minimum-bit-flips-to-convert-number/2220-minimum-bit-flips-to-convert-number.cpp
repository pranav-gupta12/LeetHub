 class Solution {
public:
    int minBitFlips(int x, int y) {
  int count = 0;
        long long  difference = x ^ y;
        while(difference){
            if(difference & 1) count++;
            difference>>=1;
        }
        return count;
    }
    
};