class Solution {
public:
    string addStrings(string num1, string num2) {
        int one = num1.length()- 1;
        int two = num2.length()- 1;
        string ans="";
        int carry = 0;
        map<char,int> mChar = {{'0',0}, {'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9}};
        int d1,d2;
        while( one>=0 || two >= 0 || carry!=0)
        {
            if(one>=0) d1 = mChar[num1[one]];
            else
                d1=0;
              if(two>=0) d2 = mChar[num2[two]];
            else
                d2=0;
            int sum = d1 + d2 + carry;
            ans+= sum%10 + '0';
            carry = sum/10;
            one--;two--;         
        }
       reverse(ans.begin(),ans.end());
        return ans;
    }
};