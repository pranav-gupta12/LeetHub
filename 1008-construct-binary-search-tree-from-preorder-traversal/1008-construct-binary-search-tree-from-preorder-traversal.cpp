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
     TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* curr = root;
        TreeNode* to_be_inserted= new TreeNode( val);
        while(root){
            if(root->val>val){
                if(root->left==NULL) {root->left = to_be_inserted; return curr;}
                root = root->left;
            }
            else{
                if(root->right==NULL) {root->right = to_be_inserted; return curr;}
                root = root->right;
            }
            
            
        }
        return curr;
    } 
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size()<2) return root;
        for( int i=1;i<preorder.size();i++){
            insertIntoBST(root,preorder[i]);
        }
        
        return root;
    }
};