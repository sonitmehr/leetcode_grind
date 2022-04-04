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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next=head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        for(int i = 0;i<k-1;i++){
            head = head ->next;
        }
        int val1 = head->val;
        head = dummy;
        for(int i = 0;i<k;i++){
            fast = fast->next;
            
        }
        while(fast!=NULL){
            fast = fast -> next;
            slow = slow->next;
        }
        int val2 = slow ->val;
        slow -> val = val1;
        for(int i = 0;i<k;i++){
            head = head -> next;
        }
        head ->val = val2;
        //cout << "val1 " << val1 << "val2 " << val2 ;
        return dummy -> next;
    }
};
