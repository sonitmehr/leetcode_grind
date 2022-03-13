class Solution {
public:
    void reverse1(vector<vector<int>> &temp,vector<int> &v,vector<int> &a,int i,int n){
    if(i ==n){
        
        temp.push_back(v);
        //cout << endl;
        return;

    }v.push_back(a[i]);
    reverse1(temp,v,a,i+1,n);
    v.pop_back();
    reverse1(temp,v,a,i+1,n);


    //printf("%d ",i);
   // printf("%d ",i);



    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> temp;
        vector<int> v;
        reverse1(temp,v,nums,0,n);
        return temp;
    }
};
