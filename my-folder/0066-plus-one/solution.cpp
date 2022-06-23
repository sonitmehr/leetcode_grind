class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        int n = v.size();
        if(n==1){
            if(v[0] == 9)return {1,0};
            v[0]++;
            return v;
        }
        int ind = n-1,flag=0;
        while(ind >=0){
            
            v[ind]++;
            if(v[ind] == 10){
                v[ind] %=10;
                ind--;
            }
            else break;            
        }
        if(ind == -1){
            v.insert(v.begin(),1);
        }
        
        return v;
    }
};
// [4,3,2,1,9]
