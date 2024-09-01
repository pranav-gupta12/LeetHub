class Solution {
public:
    void find_nearest(priority_queue<int>& distances, vector<int>& ans,int x,int y,int i ){
        int temp = abs(x) + abs(y);
        if(temp < distances.top()){
            distances.pop();
            distances.push(temp);
        }
        ans[i] = distances.top();
    }
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> distances;
        int n = queries.size();
        vector<int> ans(n,-1);
        if(k>n) return ans;
        for(int i=0;i<k-1;i++){
            distances.push( abs(queries[i][0]) + abs(queries[i][1])  );
        }
        distances.push( abs(queries[k-1][0]) + abs(queries[k-1][1])  );
        ans[k-1] = distances.top();
        for(int i=k; i<n;i++){
            find_nearest(distances,ans,queries[i][0],queries[i][1],i);
        }
        return ans;
    }
};