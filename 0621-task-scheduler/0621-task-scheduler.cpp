class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>arr(26,0);
        for(auto it : tasks){
            arr[it-'A']++;
        }
        priority_queue<int> freq;
     for(int i=0;i<26;i++){
      if(arr[i]>0) freq.push(arr[i]);
     }
        int ideal = (freq.top()-1) * n;
        int highest = freq.top();
        freq.pop();
        while(!freq.empty()){
            ideal -= min( highest-1, freq.top());
            freq.pop();
        }
        return tasks.size() + max(ideal,0);
    }
};