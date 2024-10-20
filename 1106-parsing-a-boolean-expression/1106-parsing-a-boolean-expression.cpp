class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> ch;
        for(int i=0;i<expression.size();i++){
            while(expression[i]!=')'){
                if(expression[i]==','){
                    i++;  
                }
                ch.push(expression[i]);
                i++;
            }   
            if(expression[i]==')'){
              
                  bool true_true = false;
                bool false_false = false;
                while(ch.top()!='('){
             
                    if(ch.top()=='t') true_true = true;
                    else if ( ch.top()=='f') false_false = true;
              ch.pop();  }
                if(ch.top()=='(') ch.pop();
                if(ch.top()=='&'){
                    ch.pop();
                    if(false_false==false) ch.push('t');
                    else
                        ch.push('f');
                }
                else if(ch.top()=='|'){
                       ch.pop();
                    if(true_true==true) ch.push('t');
                    else ch.push('f');
                }
                else if(ch.top()=='!'){
                   ch.pop();
                    if(false_false==true) ch.push('t');
                    else
                        ch.push('f');
                  
                }
            }
        }
        if(ch.top()=='t') return true;
        else
            return false;
    }
};