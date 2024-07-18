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
    
      int res = 0;

    vector<int> dfs(TreeNode* root, int distance) {
        vector<int> leafDist(11, 0);
        if (root == nullptr) {
            return leafDist;
        } else if (root->left == nullptr && root->right == nullptr) {
            leafDist[1] = 1;
            return leafDist;
        }

        vector<int> leftLeafDist = dfs(root->left, distance);
        vector<int> rightLeafDist = dfs(root->right, distance);

        for (int d1 = 1; d1 <= distance; d1++) {
            for (int d2 = 1; d2 <= distance; d2++) {
                if (d1 + d2 <= distance) {
                    res += leftLeafDist[d1] * rightLeafDist[d2];
                }
            }
        }

        for (int d = 1; d < 11; d++) {
            leafDist[d] = leftLeafDist[d - 1] + rightLeafDist[d - 1];
        }

        return leafDist;
    }
    int countPairs(TreeNode* root, int distance) {
         dfs(root, distance);
        return res;
    }
};