/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)return head;
        Node* curr = head;
        // Making zigzag pattern.
        while(curr!=NULL){
            Node* temp = curr ->next;
            curr -> next = new Node(curr->val);
            curr -> next -> next = temp;
            curr = temp;
        }
        curr = head;
        // Assigning random in the copied.
        while(curr!=NULL){
            if(curr->next!=NULL){
                if(curr->random!=NULL){
                    // curr -> next -> random is random of copied list.
                    // curr -> random -> next is random of original list.
                    curr -> next -> random = curr -> random -> next;
                }
                else curr -> next -> random = NULL;
                
            }
            curr = curr -> next -> next;
        }
        // Seperate the zigzag.
        Node* orig = head;Node* copy = head -> next;
        Node* temp1 = copy;
        while(copy !=NULL && orig !=NULL ){
            orig -> next = orig -> next -> next;
            if(copy->next!=NULL)copy -> next = copy -> next -> next;
            orig = orig -> next;
            copy = copy -> next;
            
        }
        return temp1;
            
            
            
            
            
            
            
            
            
    }
};
