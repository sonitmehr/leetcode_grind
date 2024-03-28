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
    void reorderList(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;
        
        while(temp != NULL){
            vec.push_back(temp->val);
            temp = temp -> next;
        }

        int i = 0,j = vec.size() - 1;

        vector<int> ans;
        while(i < j){
            ans.push_back(vec[i]);
            ans.push_back(vec[j]);
            
            i ++;
            j --;
        }
        if(i == j){
            ans.push_back(vec[j]);

        }
        temp = head;
        i = 0;
        while(temp != NULL){
            temp -> val = ans[i];
            temp = temp -> next;
            i ++;
        }

    }
};
