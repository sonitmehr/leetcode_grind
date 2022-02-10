class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int flag = 0; // Flag = 0 means 'a' is only seen till now
                      // Flag = 1 means 'b' is now seen.
        for(auto i :s){
            if(i == 'b'){
                flag =1;
                
            }if(i == 'a' && flag ==1)return false;
        }return true;
        
    }
};
