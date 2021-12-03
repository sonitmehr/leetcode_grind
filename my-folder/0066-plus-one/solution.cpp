class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int ind = n-1; 
        while(ind>=0){
            digits[ind]++;
            if(digits[ind] == 10){ // this will result in i = -1;
                digits[ind]%=10;
                ind--;
                
            }else{
                break;
            }
        }
        if(ind == -1){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
    
};
