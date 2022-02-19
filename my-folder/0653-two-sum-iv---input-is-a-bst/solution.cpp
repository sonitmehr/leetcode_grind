class right_it{
private:
    TreeNode* root;
    stack<TreeNode*> s;
public:
    right_it(TreeNode* cur){
        root=cur;
        precompute(root);
    }
    
    void precompute(TreeNode* root){
        while(root){
            s.push(root);
            root=root->right;
        }
    }
    
    int next(){
        int res;
        root=s.top(); s.pop();
        res=root->val;
        root=root->left;
        precompute(root);
        return res;
    }
};

class left_it{
private:
    TreeNode* root;
    stack<TreeNode*> s;
public:
    left_it(TreeNode* cur){
        root=cur;
        precompute(root);
    }
    
    void precompute(TreeNode* root){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    
    int next(){
        int res;
        root=s.top(); s.pop();
        res=root->val;
        root=root->right;
        precompute(root);
        return res;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        left_it l(root); right_it r(root);
        int low=l.next(); int high=r.next();
        while(low<high){
            if(low+high==k) return true;
            if(low+high<k) low=l.next();
            else high=r.next();
        }
        return false;
    }
};
