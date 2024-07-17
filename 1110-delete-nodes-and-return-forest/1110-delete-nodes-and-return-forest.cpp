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
    void helper(TreeNode* root, unordered_map<int, bool>& toDelete, vector<TreeNode*>& result, TreeNode* parent, bool isLeft) {
        if (!root) return;

        // Recursively traverse left and right subtrees
        helper(root->left, toDelete, result, root, true);
        helper(root->right, toDelete, result, root, false);

        // If the current node needs to be deleted
        if (toDelete[root->val]) {
            if (root->left) result.push_back(root->left);  // Add left child to the result if it exists
            if (root->right) result.push_back(root->right); // Add right child to the result if it exists
            if (parent) {
                if (isLeft) parent->left = nullptr;  // Remove the current node from its parent
                else parent->right = nullptr;
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
      unordered_map<int, bool> toDelete;
        for (int val : to_delete) {
            toDelete[val] = true;
        }
        
        vector<TreeNode*> result;
        helper(root, toDelete, result, nullptr, false);
        
        // If the root is not deleted, add it to the result
        if (!toDelete[root->val]) {
            result.push_back(root);
        }
        
        return result;
        }
    
};