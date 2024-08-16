class Solution {
public:
    typedef pair<int,int> P; // valuee,row
    
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<P, vector<P>, greater<P>> minheap;
        for(int i=0;i<arrays.size();i++){
            minheap.push({arrays[i][0], i});
        }
        int ans=-1;
        for(int i=0;i<arrays.size();i++){
            P top = minheap.top();
            bool remove = false;
            int mini = top.first;
            int row = top.second;
            if(row==i) {
                minheap.pop();
                remove=true;
            }
            ans = max(ans, abs(arrays[i].back() - minheap.top().first ));
            if(remove) minheap.push(top);
        }
       return ans; 
    }
};