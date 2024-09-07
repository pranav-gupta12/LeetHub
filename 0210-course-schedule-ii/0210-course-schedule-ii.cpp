class Solution {
public:
     bool is_possible(unordered_map<int,vector<int>>& mapping, vector<bool>& visited,  vector<bool>& dfsvisited,int node,stack<int>& ans ){
        visited[node]= true;
        dfsvisited[node] = true;

        for(auto it : mapping[node]){
        if(visited[it]==false) {
            if(is_possible(mapping,visited,dfsvisited,it,ans)==true) return true;
        }
            else if (dfsvisited[it]==true) return true;
            
        }
         ans.push(node);
       dfsvisited[node] = false;
       return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      unordered_map<int,vector<int>> mapping;
     vector<bool> visited(numCourses,false);
    vector<bool> dfsvisited(numCourses,false);
        for(auto &it : prerequisites){ mapping[it[1]].push_back(it[0]);
                                      }
        stack<int> ans;
        for(int i=0;i<numCourses;i++){
            if(visited[i]==false)
            if(is_possible(mapping,visited,dfsvisited,i,ans)==true) return {};
         }
        vector<int> result;
        while(!ans.empty()){
            result.push_back(ans.top());
            ans.pop();
        }
        return result;
    }
};

