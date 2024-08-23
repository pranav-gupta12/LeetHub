class Solution {
public:
    string fractionAddition(string expression) {
        int num=0,den=1;
        for(int i=0;i<expression.size();i++){
            bool isneg = (expression[i]=='-');
         if(expression[i] == '+' || expression[i] == '-') {
                i++;
            }
            int currnum = expression[i] -'0';
            if(expression[i+1]=='0'){ currnum= 10; i++;}
            i+=2;
            
             if(isneg == true) {
                currnum *= -1;
            }

            int currden = expression[i] - '0';
            if(i+1<expression.length() && expression[i+1]=='0' ){
                currden = 10;
                i++;
            }
            num =  num*currden + currnum*den;
            
             den = den*currden;
        }
        int gcd= abs(__gcd(num,den));
        num/=gcd;
        den/=gcd;
        string ans = to_string(num) + '/' + to_string(den);
        return ans;
    }
};