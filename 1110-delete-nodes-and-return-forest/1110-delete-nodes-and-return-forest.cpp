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
     TreeNode* dfs(TreeNode* node, unordered_set<int>& toDelete, vector<TreeNode*>& result) {
        if (!node) return nullptr;

        node->left = dfs(node->left, toDelete, result);
        node->right = dfs(node->right, toDelete, result);

        if (toDelete.count(node->val)) {
            if (node->left) result.push_back(node->left);
            if (node->right) result.push_back(node->right);
            return nullptr;
        }

        return node;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
         unordered_set<int> toDelete(to_delete.begin(), to_delete.end());
        vector<TreeNode*> result;
        
        if (!toDelete.count(root->val)) {
            result.push_back(root);
        }

        dfs(root, toDelete, result);

        return result;
    }
};