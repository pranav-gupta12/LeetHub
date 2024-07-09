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
    int height(TreeNode* node){
 if(node == NULL) return 0;
        
        int left = height(node ->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        int left = 0;
        int right = 0;
        if(root==NULL) return true;
        if(root->left !=NULL) left = height(root->left);
        if(root->right) right = height(root->right);
        if(abs(left-right)<=1  && isBalanced(root->left) &&
            isBalanced(root->right)) return true;
        return false;
        
    }
};