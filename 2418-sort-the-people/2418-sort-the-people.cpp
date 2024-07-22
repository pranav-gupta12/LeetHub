class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string> mapping;
        for(int i=0;i<heights.size();i++){
            mapping[heights[i]] = names[i];
        }
        sort(heights.begin(),heights.end());
        int k=0;
        for(int i=heights.size()-1;i>=0;i--){
            names[k++] = mapping[heights[i]];
            
        }
        return names;
    }
};