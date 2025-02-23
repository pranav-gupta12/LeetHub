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
    TreeNode* solve(string traversal, int& idx, int depth){
        int n = traversal.length();
        if(idx>=n)  return NULL;
        int curr_depth = 0;
        int j = idx;
        while( j<n && traversal[j]=='-') j++;
        curr_depth = j-idx;
        if(curr_depth != depth) return NULL;
        int val;
        string curr_val = "";
        while(j<n && isdigit(traversal[j])) {
            curr_val+= traversal[j];
            j++;
        }
        val = stoi(curr_val);
        TreeNode* ans = new TreeNode(val);
        idx = j;
        ans->left = solve(traversal,idx, depth+1);
        ans->right = solve(traversal,idx,depth+1);
        return ans;


    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        int idx = 0;
        return solve(traversal,idx,0);
    }
};