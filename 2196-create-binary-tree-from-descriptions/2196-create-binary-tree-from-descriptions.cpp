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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
         unordered_map<int, TreeNode*> mapping;
        unordered_set<int> children;

        for (const vector<int>& it : descriptions) {
            int parentVal = it[0];
            int childVal = it[1];
            bool isLeft = it[2] == 1;

            // Create parent node if it doesn't exist
            if (mapping.find(parentVal) == mapping.end()) {
                mapping[parentVal] = new TreeNode(parentVal);
            }
            TreeNode* parent = mapping[parentVal];

            // Create child node if it doesn't exist
            if (mapping.find(childVal) == mapping.end()) {
                mapping[childVal] = new TreeNode(childVal);
            }
            TreeNode* child = mapping[childVal];

            // Link the child to the parent
            if (isLeft) {
                parent->left = child;
            } else {
                parent->right = child;
            }

            // Track the child nodes
            children.insert(childVal);
        }

        // Find the root node (which is not a child of any node)
        TreeNode* root = nullptr;
        for (const vector<int>& it : descriptions) {
            if (children.find(it[0]) == children.end()) {
                root = mapping[it[0]];
                break;
            }
        }

        return root;
    }
};