class Solution {
public:
    string makeGood(string s) {
        string ans;
        stack<char> stack;
        for(auto i : s){
            if(!stack.empty() && abs((int)stack.top()- (int)i)==32) stack.pop();
            else
                stack.push(i);
        }
        while(!stack.empty()){
            ans = stack.top() + ans;
            stack.pop();
        }
            
        return ans;
        
    }
};