/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, int i, unordered_map<int,long long>& mp){
        if(!root) return;
                mp[i] += root->val;
        traverse(root->left,i+1,mp);
        traverse(root->right,i+1,mp);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<int,long long> mp;

        traverse(root,0,mp);
        if(mp.size()<k) return -1;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(auto &it : mp){
            pq.push(it.second);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
        
    }
};