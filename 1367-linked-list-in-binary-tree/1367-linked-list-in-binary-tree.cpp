/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void traverseTree(TreeNode* root, int target, vector<TreeNode*>& vec){
        if(root->val == target) vec.push_back(root);
        if(root->left!=NULL) traverseTree(root->left,target,vec);
         if(root->right!=NULL) traverseTree(root->right,target,vec);
        
        
    }
    bool check_path(TreeNode* root, ListNode* head){
      if(head==NULL) return true;
        if(root==NULL) return false;
        if(head->val!=root->val) return false;
        return check_path(root->left,head->next) || check_path(root->right, head->next);
        
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        // find all head value in tree 
        // check path for every one
        
       vector<TreeNode*> vec;
         traverseTree(root,head->val,vec);
        if(vec.size()==0)return false;
        for(int i=0;i<vec.size();i++){
            if(check_path(vec[i],head)==true) return true;
        }
        return false;
    }
};