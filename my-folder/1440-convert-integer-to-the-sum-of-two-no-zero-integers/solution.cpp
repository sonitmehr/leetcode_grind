class Solution {
public:

    bool check(int n){
        while(n > 0){
            if(n%10 ==0)return true;
            n/=10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        int a = n - 1;
        while(a > 0){
            int b = n - a;
            if(check(a) == false && check(b) == false)return {a,b};
            a--;
        }

        return {0,0};
    }
};
