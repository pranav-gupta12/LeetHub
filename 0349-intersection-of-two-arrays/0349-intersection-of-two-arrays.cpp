class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       set<int> track1;
        for(int it: nums1) track1.insert(it);
        vector<int> ans;
        for(int it: nums2 ) if(track1.count(it)){ ans.push_back(it); track1.erase(it);}
        return ans;
    }
};