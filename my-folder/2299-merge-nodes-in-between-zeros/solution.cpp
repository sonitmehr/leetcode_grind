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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* finale = new ListNode(0);
        //finale = NULL;
        ListNode* tempHead = head;
        ListNode* dummy = finale;
        
//dummy -> next = 
        while(head!= NULL){
            
            if(head -> next != NULL && head -> val == 0){
                int count = 0;
                //finale = dummy;
                head = head -> next;
                while(head -> val != 0){
                    count += head->val;
                    head = head -> next;
                }
                
                dummy -> next = new ListNode(count);
                dummy = dummy -> next;
            }else {
                head = head -> next;
        
            }
        }
        //dummy -> next = NULL;
        return finale -> next;
    }
};
