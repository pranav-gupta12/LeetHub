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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(),nums.end());
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL){
            if(st.find(temp->val) != st.end()){
                if(prev==NULL){
temp = temp->next;
                    head->next = NULL;
                    head = temp;
                }
                else
                {
                    prev->next = temp->next;
                    temp->next=NULL;
                    temp = prev;
                }
                
            } 
            else
            {
                prev =  temp;
                temp = temp->next;
            }
        }
        return head;
    }
};