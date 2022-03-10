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
//#define int long long;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while(l1!=NULL || l2!= NULL || carry ==1){
            int sum = 0;
            if(l1!=NULL){
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2!=NULL){
                sum += l2 -> val;
                l2 = l2 -> next;
                
            }
            sum += carry;
            carry = sum/10;
            
            dummy -> next = new ListNode(sum%10); 
            dummy = dummy -> next;
        }
        return temp -> next;


        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        /*if(l1->next == NULL && l2 ->next == NULL){
            return new ListNode(l1 ->val + l2 -> val);
        }
        long long counter1 = 0,counter2=0,l1sum=0,l2sum=0;
        while(l1!=NULL){
            
            l1sum += (l1->val)*pow(10,counter1);
            counter1++;
            
            l1=l1->next;
        }
        while(l2!=NULL){
            
            l2sum += (l2->val)*pow(10,counter2);
            counter2++;
            
            l2=l2->next;
        }long long sum = l1sum+l2sum;
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        if(sum == 0)return new ListNode(0);
        while(sum!=0){
            long long remain = sum%10;
            sum=sum/10;
            ListNode* ans = new ListNode(remain);
            dummy -> next = ans;
            dummy = dummy -> next;
        }
        
        cout << l1sum << endl;
        cout << l2sum << endl;
        return temp->next;
        */
    }
};
