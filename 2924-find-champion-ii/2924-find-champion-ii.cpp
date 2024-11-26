class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        set<int> st;
        for(auto v: edges){
  
            st.insert(v[1]);
        }
       if(st.size() !=n-1 ) return -1;
        int temp = 0;
        while(!st.empty()){
            int top = *st.begin();
            if(top>temp) return temp;
            temp++;
            st.erase(*st.begin());
        }
        return n-1;
    }
};