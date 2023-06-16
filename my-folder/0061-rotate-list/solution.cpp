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
        int len = 1;
     if(head == NULL || head->next==NULL || k == 0)return head;
     ListNode* temp = head;
     while(temp -> next != NULL){
          len++;
          temp = temp -> next;
     }
     // cout << temp->val << " ";
     k = k % len;
     int val = len - k;
     // cout << len << " " << val << " ";
     temp -> next = head;
     while(val--){
          temp = temp -> next;
     }
     // cout << temp->val << " ";
     head = temp -> next;// = head;
      temp -> next = NULL;
      return head;
    }
};
