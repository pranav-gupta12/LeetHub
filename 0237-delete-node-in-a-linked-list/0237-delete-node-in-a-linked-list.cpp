/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int data ;
        ListNode* temp = node;
        ListNode* newTail;
        while(temp->next!=NULL){
            if(temp->next->next==NULL) newTail = temp;
            temp->val = temp->next->val;
            temp = temp->next;
            
        }
        newTail->next = NULL;
        
    }
};