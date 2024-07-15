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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(auto &i : nums)st.insert(i);
        
       
        
        while(head != NULL && st.find(head->val) !=st.end()){
            head=head->next;
        }
         ListNode* temp = head;
        while(head != NULL){
            while(head->next != NULL && st.find(head->next->val) != st.end()){
                
                head->next=head->next->next;
                
            }
            if(head != NULL){
                            head = head -> next;

            }
        }
        return temp;
    }
};
