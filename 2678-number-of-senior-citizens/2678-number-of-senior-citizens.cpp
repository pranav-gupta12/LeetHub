class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto it: details){
            string age ="";
            age+= it[11];
            age+=it[12];
            if(stoi(age)>60)ans++;
        }
        return ans;
    }
};