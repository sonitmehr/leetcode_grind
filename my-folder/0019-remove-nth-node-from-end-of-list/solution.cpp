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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode() ; // Need to initialize.
        dummy->next = head; // Dummy is one step behind head.
        
        ListNode* fast = dummy;
        ListNode* slow = dummy; 
        
        // [dummy(fast)(left),1,2,3,4,5]
        
        for(int i = 0;i<=n;i++){//  Runs 'n+1' times.
            fast = fast -> next;
            
        }// [dummy(left),1, 2,3(fast),4,5]  Fast reaches 1 step behind node to be deleted.
        while(fast !=NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        return dummy -> next;
    }
};
