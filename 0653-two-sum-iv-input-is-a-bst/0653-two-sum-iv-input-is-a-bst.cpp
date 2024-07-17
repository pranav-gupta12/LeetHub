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
    void traversal(TreeNode* root, vector<int>& inorder){
        if(root==NULL) return ;
        traversal(root->left,inorder);
        inorder.push_back(root->val);
        traversal(root->right,inorder);
    }
    bool helper(vector<int>& inorder, int &k){
        int s = 0;
        int e = inorder.size() - 1;
        while(s<e){
            if(inorder[s] + inorder[e] == k) return true;
            else if (inorder[s] + inorder[e]<k ){
                s++;
            }
            else
            {
               e--; 
            }
        }
        return false;
        
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        traversal(root,inorder);
        return helper(inorder,k);
    }
};