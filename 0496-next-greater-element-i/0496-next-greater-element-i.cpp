class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]] = i;
            
        }
        for(int i=0;i<nums1.size();i++){
            int index = m[nums1[i]];
            for(int j = index;j<nums2.size();j++){
                if(nums2[j]> nums1[i]){
                    ans.push_back(nums2[j]);
                    break;
                }
                if(j==nums2.size()-1){
                    ans.push_back(-1);
                    break;
                }
                
            }
        }
        return ans;
    }
};