class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int num1 = ((int)(coordinate1[0] - 'a' +1) + (int)(coordinate1[1] -'0') );
          int num2 = ((int)(coordinate2[0] - 'a' +1) + (int)(coordinate2[1] -'0')  );
        if(num1%2 == num2%2) return true;
        return false;
    }
};