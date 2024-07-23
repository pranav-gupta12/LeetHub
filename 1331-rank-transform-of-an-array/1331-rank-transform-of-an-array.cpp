class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int N = arr.size();
         priority_queue<int,vector<int>,greater<int>> minheap;
    for(auto it: arr){
        minheap.push(it);
    }
    int curr = 1;
    unordered_map<int,int> mapping;
   while(!minheap.empty()){
       int top = minheap.top();
       minheap.pop();
       while(!minheap.empty() && minheap.top()==top) {
           minheap.pop();
       }
       mapping[top]= curr++;
   }
for(int i=0;i<N;i++){
    
    arr[i] = mapping[arr[i]];
}
return arr;
    }
};