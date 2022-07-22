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
    ListNode* partition(ListNode* head, int x) {
        ListNode * left = new ListNode(0);
        ListNode * right = new ListNode(0);
        ListNode * temp1 = left;
        ListNode * temp2 = right;
        while(head != NULL){
            if(head -> val < x){
                left-> next = new ListNode(head->val);
                cout << "left->val " << left-> val << endl;
                //left -> next = NULL;
                
                left = left -> next;
            }
            else{
                right->next = new ListNode(head->val);
                cout << "right->val " << right-> val << endl;
                //right -> next = NULL;
                right = right -> next;
            }
            head = head-> next;
            
        }
        left->next = temp2->next;
        
        return temp1->next;
    }
};
