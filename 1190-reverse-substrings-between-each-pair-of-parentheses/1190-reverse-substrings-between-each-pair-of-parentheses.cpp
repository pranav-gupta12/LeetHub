class Solution {
public:
    string reverseParentheses(string s) {
         stack<int> st; //stack using to store indices of '('
        int n = s.size();
        //Traversing the loop to track '(' and ')'
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
            {
                //when found '(' then put the substring into the stack
                st.push(i); 
            }
            else if(s[i] == ')')
            {
                //when found ')' then reverse the substring inside '(' and ')'
                reverse(s.begin() + st.top() , s.begin() + i); 
                st.pop(); //remove the index of '(' from the stack
            }
        }
        //traversing for store the final result without '(' and ')'
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            if(s[i] != '(' && s[i]  != ')')
            {
                ans += s[i];
            }
        }
        return ans;
    }
};