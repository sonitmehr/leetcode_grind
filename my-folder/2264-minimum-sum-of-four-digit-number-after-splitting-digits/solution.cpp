class Solution {
public:
    int minimumSum(int num) {
        
        string s;
        //  rem = 2392
        while(num!=0){
            int rem = num%10;
            num = num/10;
            s += (rem + '0');
            
        }
        sort(s.begin(),s.end()); // 2239
        string s1 = "";
        s1 = s1 + s[0] + s[3];
        string s2 = "";
        s2 = s2 + s[1] + s[2];
        cout << s1;
        return stoi(s1) + stoi(s2); 
        
        
        
    }
};
