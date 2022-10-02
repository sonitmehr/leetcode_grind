class Solution {
public:
    int commonFactors(int a, int b) {
        
        int cnt = 0;
        for(int i =1;i<=min(a,b);i++){
            if(b%i == 0 && a%i==0){
                cout << i <<  " ";
                cnt++;
            }
        }
        return cnt;
    }
};
