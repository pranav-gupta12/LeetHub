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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        unordered_map<ListNode* , bool> index;
        ListNode* temp = head;
        // int idx = 0;
        while(temp!=NULL){
            if(index[temp]) return temp;
            index[temp]= 1;
            temp = temp->next;
            
        }
        return NULL;
    }
};