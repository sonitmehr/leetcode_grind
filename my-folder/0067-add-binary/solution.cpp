class Solution {
public:
    
    
    
    
    string addBinary(string a, string b) {
        int n1 =a.size(),n2 = b.size(); 
        int carry = 0;
        string s1;
        //f(a,b,n1,n2);
        //cout << a << " " << b << endl;
        int sum = 0;
        int i = n1-1,j = n2-1;
        while(i>=0 || j >=0 || carry){
            sum = 0;
            if(i>=0){
                sum += (a[i] - '0');
                i--;
            }
            if(j>=0){
                sum += (b[j] - '0');
                j--;
            }
            sum += carry;
            cout << "SUM " << sum << " ";
            
            if(sum == 1){
                carry = 0;
                s1+="1";
            }else if(sum == 2){
                carry = 1;
                s1+="0";
            }
            else if(sum == 0){
                carry = 0;
                s1+="0";
            }else if(sum == 3){
                carry = 1;
                s1+="1";
            }
            //"1111"
            //"1111"
            
        }
        reverse(s1.begin(),s1.end());
        return s1;
    }
    
    
};
