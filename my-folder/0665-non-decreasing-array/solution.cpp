class Solution {
public:
    bool checkPossibility(vector<int>& v) {
        int n = v.size();
        if(n==1)return true;
        int l = 0,r = 1;
        int cnt = 1;
        while(r < n){
            if(v[r] < v[l]){
                if(cnt == 0)return false;
                // compare with v[l-1]
                if(l==0 || v[l-1] <= v[r])v[l] = v[r]; // change v[l] to v[r]
                else v[r] = v[l];
                cnt--;
            }
            
            l++;r++;
        }
        
        return true;
    }
};
// [3,4,2,3]
/*
[4,2,3]
[4,2,1]
[3,4,2,3]
*/
