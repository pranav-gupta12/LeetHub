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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        ListNode* next = temp->next;
        if(next==NULL) return head;
        while(next!=NULL){
            int gcd = __gcd(temp->val, next->val);
            temp->next = new ListNode(gcd);
            temp->next->next = next;
            temp = next;
            next = next->next;
        }
        return head;
    }
};