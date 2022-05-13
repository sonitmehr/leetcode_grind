class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            Node* prev = NULL;
            Node* tmp;
            while(n--){
                tmp = q.front();
                if(prev)prev->next = tmp;
                prev = tmp;
                q.pop();
                if(tmp->left)q.push(tmp->left);
                if(tmp->right)q.push(tmp->right);      
            }
            tmp->next = NULL;
        }
        return root;
    }
};
