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
    int sizeoflist(ListNode* head){
        if(head!=NULL) return 1 + sizeoflist(head->next);
        else return 0;
    }
    ListNode* getnext(ListNode* temp, int gap){
        ListNode* prev = temp;
        while(temp!=NULL && gap>0){
            prev = temp;
            temp = temp->next;
            gap--;
            
        }
        prev->next=NULL;
        return temp;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       
        
        int size = sizeoflist(head); //10
       
        vector<ListNode*> ans(k);
          if(head==NULL) return ans;
        if(head->next==NULL) {ans[0]=head;return ans;}
        int gap = size / k; //3
        int rem = size % k; //1
        int count=0; 
        ListNode* temp = head; 
        int idx=0;
        while(count < size){
            ans[idx++] = temp;///{1,}
            if(rem>0) {
                rem--;//1
                temp = getnext(temp,gap+1);//
                count+=gap+1;
            }
            else{
                temp = getnext(temp,gap); count+=gap;}
            
        }
        return ans;
    }
};