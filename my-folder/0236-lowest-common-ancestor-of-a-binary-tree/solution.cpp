class Solution {
public:
    
    TreeNode* bfs(TreeNode* &root, TreeNode* p, TreeNode* q){
        
        //int vp = p -> val;
        //int vq = q -> val;
        if(root == NULL)return root;
        
        TreeNode * l = bfs(root->left,p,q);
        TreeNode * r = bfs(root->right,p,q);
        
        if(root -> val == p-> val || root -> val == q -> val)return root;
        if(l!=NULL and r!=NULL) return root;
        if(l == NULL && r == NULL)return NULL;
        
        if(l != NULL)return l;
        return r;
        
        
        /*
        if(!bfs(root-> left,p,q) && !bfs(root->right,p,q))return root;
        
        else if(bfs)
        */
        
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        
        if(p -> val == root-> val || q-> val == root->val || root == NULL)return root;
         
        return bfs(root,p,q);
        

    }
};
