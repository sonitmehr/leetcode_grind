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
        Node* copy;
        
        while(curr!=NULL){
            Node* temp = curr->next;
            curr -> next = new Node(curr -> val);
            //curr -> next = copy;
            curr -> next -> next = temp;
            curr = temp;
        }
        curr = head;
        //return head;
        while(curr!=NULL){
            if(curr -> next != NULL){
                if(curr -> random != NULL){
                    curr -> next -> random = curr -> random -> next;
                }else curr -> next -> random = NULL;
            }   
            curr = curr -> next -> next;
        }
        Node* orig = head;
        Node* cop = head -> next;
        Node* temp1 = cop;
        
        while(cop != NULL && orig != NULL){
            orig -> next = orig -> next -> next;
            if(cop -> next != NULL)cop -> next = cop -> next -> next;
            orig = orig -> next;
            cop = cop -> next;       
            
        }
        
        return temp1;
    }
};
