class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = num1;
        int k1 = __builtin_popcount(num1);
        int k2 = __builtin_popcount(num2);
        //cout << k1 << " " << k2;
        if(k1 > k2){
            int t = num1;
            int diff = k1 - k2;
            for(int i = 0;i<32;i++){
                int val = (1 << i) & num1;
                //cout << val << " ";
                if(((1 << i) & num1)){
                    diff--;
                    //cout << (1 << i) << " ";
                    num1 = ~(1 << i) & num1;
                    
                }
                if(diff == 0)return num1;
                
            }
//             for(int i = 31;i>=0;i--){
//                 int val = (1 << i) & t;
//                 //cout << val << " ";
                
//                 if(((1 << i) & t)){
//                     diff--;
//                     num1 = ~(1 << i) & num1;
//                     cout << i;
//                 }
//                 if(diff == 0)return num1;
//                 // 1100
//                 // 0100
//                 // 0001
//             }
        }
        else if(k1 < k2){
            int t = num1;
            int diff = k2 - k1;
            for(int i = 0;i<=32;i++){
                int val = (1 << i) & num1;
                //cout << val << " ";
                if(((1 << i) & num1) == 0){
                    diff--;
                    //cout << (1 << i) << " ";
                    num1 = (1 << i) | num1;
                    
                }
                if(diff == 0)return num1;
                
            }
        }
        return num1;
    }
};
