class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> track;
        for(int i=0;i<list1.size();i++){
            track[list1[i]] = i;
        }
        vector<string> ans;
        int index=INT_MAX;
        unordered_map<int,list<string>> mapping;
        for(int i=0;i<list2.size();i++){
            if(track.count(list2[i])!=0 ){
                int curr = i+track[list2[i]];
                mapping[curr].push_back(list2[i]);
                index=min(index,curr);
            }
        }
        for(auto it : mapping[index]){
            ans.push_back(it);
        }
        return ans;
    }
};