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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp;
        ListNode* first;
        ListNode* temp1 = head;
        int size = 0;
        if (head == NULL || head -> next == NULL)return head;
        while(temp1!=NULL){
            temp1 = temp1 -> next;
            size++;
        }k = k%size;
        while(k--){
            temp = head;
            
            
            while(head -> next->next != NULL){
                head = head -> next;
            }
            first = new ListNode(head->next->val);
            head -> next = NULL;
            first -> next = temp;
            head = first;
            
            
        }
        return first;
    }
};
