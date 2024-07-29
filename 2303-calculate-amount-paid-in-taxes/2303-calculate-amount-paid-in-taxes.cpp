class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double ans = 0;
        int prev = 0;
       
        for(auto it : brackets){
            int curr = min(it[0] - prev, income);
            income -= curr;
            ans+= curr* (0.01*it[1]);
            prev = it[0];
            if(income==0) return ans;
            
            
            
        }
        return ans;
    }
};