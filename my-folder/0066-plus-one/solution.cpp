class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        // [9] = [1,0]
        // [7,9] = [7,0]
        // [9,9,9,9,9,9,9,9,9] = [1,0,0]
        // vectors.insert(v.begin(),1);
        int i = n-1;
        while(i>=0){
            digits[i]++;
            if(digits[i] == 10){
                digits[i]=0;
                i--;
            }
            else{
                break;
            }
        }
        if(i == -1)digits.insert(digits.begin(),1);
        return digits;
            
    }
};
