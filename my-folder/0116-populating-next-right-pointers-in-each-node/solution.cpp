/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // COPIED CODE. IT WAS DONE FOR THE CHALLENGE. YOU HAVE TO TRY THIS AGAIN
    Node* connect(Node* root) {
        if(root == NULL)return root;
        
        Node* leftNode = root;
        
        while(leftNode->left != NULL){
            Node* head = leftNode;
            while(head!=NULL){
                head->left->next = head ->right;
                if(head -> next != NULL){
                    head -> right -> next = head -> next -> left;
                }
                head  = head -> next;
            }
            leftNode = leftNode -> left;
        }
        return root;
            
    }
};
