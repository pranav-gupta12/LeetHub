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
    bool isPalindrome(ListNode* head) {
         vector<int> ll;
        ListNode* temp = head;
        while(temp){
            ll.push_back(temp->val);
            temp = temp->next;
        }
        int s=0,e=ll.size()-1;
        while(s<=e){
            if(ll[s]==ll[e]){
                s++;
                e--;
            }
            else return false;
        }
        return true;
    }
};