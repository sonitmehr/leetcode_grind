class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size();
        int i;
        if(n == 1)return ;
        for(i = n -2;i>=0;i--){
            if(v[i] < v[i +1])break;
        }
        if(i < 0){
            reverse(v.begin(),v.end());
        }
        else{
            int j;
            for(j = n - 1;j>=i+1;j--){
                if(v[j] > v[i]){
                    swap(v[i],v[j]);
                    reverse(v.begin() + i + 1,v.end());
                    return;
                    
                }
            }
        }
        
        
        
    }
};
