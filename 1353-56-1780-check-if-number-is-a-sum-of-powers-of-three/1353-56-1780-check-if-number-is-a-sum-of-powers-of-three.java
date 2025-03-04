class Solution {
    public boolean checkPowersOfThree(int n) {
        int rem = 0;
        while(rem<=1 && n>0){
            rem = n%3;
            n = n/3;
        }
        if(rem<=1) return true;
        return false;
    }
}