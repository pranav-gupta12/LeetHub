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
    TreeNode* reverseOddLevels(TreeNode* root) {
       
        if(root==NULL) return root;
         // TreeNode* check = root;
        vector<TreeNode*> prev;
        bool odd = false;
        prev.push_back(root);
        while(true){
            odd = !odd;
            if(prev.front()==NULL || prev.front()->left==NULL ) break;
            vector<TreeNode* > current;
              //pushing child
                for(int i=0;i<prev.size();i++){
                    current.push_back(prev[i]->left);
                    current.push_back(prev[i]->right);
                }
            if(odd==true){
              
                // swap values
                for(int i=0;i<current.size()/2;i++){
                    int temp = current[i]->val;
                    current[i]->val = current[current.size()-i-1]->val;
                    current[current.size()-i-1]->val = temp;
                }
            }
                prev = current;
            
        }
        
        return root;
    }
};