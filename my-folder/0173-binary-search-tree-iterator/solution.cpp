/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    void inorder(TreeNode* root){
        if(root==NULL)return;

        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
    void insert(TreeNode* root,stack<TreeNode*> &st){
        while(root != NULL){
            st.push(root);
            cout << root->val <<endl;
            root=root->left;
        }
        cout << "end" << endl;
    }

    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        if(root == NULL)return;
        // inorder(root);
        // cout << endl;
        insert(root,st);
    }
    
    int next() {

        auto top = st.top();
        int val = top->val;
        cout << "top : ";
        cout << val << endl;
        st.pop();
        if(top->right != NULL){
            top = top->right;
            insert(top,st);

        }
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
