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
    private : 
    void createmapping(map<int,int>& m, vector<int>& inorder){
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        
    }
    TreeNode* solve( vector<int>& preorder, vector<int>& inorder,map<int,int>& m, int &idx, int s, int e   ){
        if(idx>=preorder.size() || s>e) return NULL;
        int element = preorder[idx++];
        TreeNode* root  =  new TreeNode(element);
        int i = m[element];
        root->left= solve(preorder,inorder,m,idx,s,i-1);
        root->right= solve(preorder,inorder,m,idx,i+1,e);
        return root;
        
        
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> nodetoin;
        createmapping(nodetoin,inorder);
        int idx=0;
        int s=0;
        int e=inorder.size()-1;
        return solve(preorder,inorder,nodetoin,idx,0,inorder.size()-1);
        
        
    }
};