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
class BSTIterator {
    
public:
    deque<int> inorder;
    void inordertraversal(TreeNode* root){
        
        if(root==NULL) return;
        inordertraversal(root->left);
        inorder.push_back(root->val);
        inordertraversal(root->right);
    }
    BSTIterator(TreeNode* root) {
        inordertraversal(root);
    }
    
    int next() {
        int ans = inorder.front();
        inorder.pop_front();
        return ans;
    }
    
    bool hasNext() {
        return !inorder.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */