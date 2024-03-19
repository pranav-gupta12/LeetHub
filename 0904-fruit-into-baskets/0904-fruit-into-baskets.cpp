class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        if(fruits.size()<3) return fruits.size();
        int n = fruits.size();
        int s=0,e=0,res=0;
        unordered_map<int,int> freq;
        while(e<n){
            freq[fruits[e++]]++;
            while(freq.size()>2){
                freq[fruits[s++]]--;
                if(freq[fruits[s-1]]==0) freq.erase(fruits[s-1]);
                
            }
            res = max(res, e-s);
        }
        return res;
    }
};