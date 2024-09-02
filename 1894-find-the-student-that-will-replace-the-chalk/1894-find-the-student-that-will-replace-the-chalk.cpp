class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total_req =0;
        for(int it : chalk) total_req += it;
     
        k  = k %  total_req;
        if(k==0) return 0;
        for(int i=0;i<chalk.size();i++){
            if(chalk[i]<=k) k = k - chalk[i];
            else return i;
        }
        return chalk.size()-1;
    }
};