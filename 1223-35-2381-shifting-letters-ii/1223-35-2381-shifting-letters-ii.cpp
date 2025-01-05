class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shift(n,0);
        for(int i=0;i<shifts.size();i++){
            int l = shifts[i][0];
            int r = shifts[i][1];
            int x;
            if(shifts[i][2]==1) x = 1;
            else x = -1;
            shift[l] += x;
            if(r+1<n) shift[r+1] -=x;
        }
        int diff = 0;
        for(int i=0;i<n;i++){
            diff += shift[i];
           
            diff = diff%26;
            if(diff<0){
                diff += 26;
            }
             s[i] = ((s[i] - 'a' + diff) % 26) + 'a';
        }
        return s;
    }
};