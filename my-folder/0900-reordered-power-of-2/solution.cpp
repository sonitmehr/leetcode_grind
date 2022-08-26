vector<map<int,int>> preCompute;
bool f = []{
     
    long val = 1;
    for(int i = 0;i<34;i++){
        // find frequency of digits.
        map<int,int> m;
        long t = val;
        while(val > 0){
            int digit = val%10;
            m[digit]++;
            val/=10;
        }
        preCompute.push_back(m);
        val = t;
        val *= 2;
    }
    return true;
}(); 
class Solution {
public:
    
    
    bool reorderedPowerOf2(int n) {
        map<int,int> m;
        int val = n;
        while(val > 0){
            int digit = val%10;
            m[digit]++;
            val/=10;
        }
        for(int i=0;i<34;i++){
            if(preCompute[i] == m)return true;
        }
        return false;
        
    }
};
// 00032
