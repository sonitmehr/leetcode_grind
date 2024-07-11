class Solution {
public:
    vector<int> singleNumber(vector<int>& v) {
        int n = v.size();
        int xori = 0 ;
        for(int i= 0;i<n;i++){
            xori ^= v[i];
        }
        
        int right = (xori & ((long long)xori - 1)) ^ xori;

        int one = 0,two = 0;

        for(int i = 0 ;i<n;i++){
            if(v[i] & right){
                one ^= v[i];
            }
            else{
                two ^= v[i];
            }
        }
        return {one,two};
    }
};
