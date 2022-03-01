class Solution {
public:
    vector<int> countBits(int n) {
                
        vector<int> v;
        v.push_back(0);
        for(int i = 1;i<=n;i++){
            int count=0;
            int temp = i;
            while(temp){
                count += temp&1;
                temp  >>= 1;
            }
            v.push_back(count);
        }
        
        
        
        
        return v;
    }
};
