class Solution {
public:
    int findComplement(int num) {
        int nums=num;
        int temp=0;
        while(nums>0){
         temp++;
        nums = nums/2;
        }
        return (pow(2,temp) - 1 - num);
    }
};