class Solution {
public:
    int xorAllNums(vector<int>& v1, vector<int>& v2) {
        int xor1 = 0,xor2 = 0;
        for(int i = 0;i<v1.size();i++)xor1 = xor1 ^ v1[i];
        for(int i = 0;i<v2.size();i++)xor2 = xor2 ^ v2[i];
        
        if(v1.size()%2==0){
            
            xor2 = 0;
        }
        if(v2.size()%2==0)xor1= 0;
        
        
        return xor1 ^ xor2;
    }
};
