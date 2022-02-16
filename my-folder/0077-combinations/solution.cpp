class Solution {
public:
    
    // Back tracking - need to do.
    vector<vector<int>>ans;

    void show(int index,int size,vector<int>ans1,int k,int n){
        if(size==k){
            ans.push_back(ans1);
        }
        for(int i=index;i<=n;i++){
            ans1.push_back(i);
            show(i+1,size+1,ans1,k,n);
            ans1.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans1;
        show(1,0,ans1,k,n);
        
        return ans;
    }
};
