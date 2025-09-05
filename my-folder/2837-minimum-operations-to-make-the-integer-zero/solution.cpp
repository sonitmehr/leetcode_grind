class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        // 3 -> 011
        // [1,2,4,8,16...]
        // [8,9,11,15,23]

        // [-1,2,6,8...]->60
        // 
        // 1,2 + 4
        // 5 -> 101
        // -14 ->

        // 10,2
        // 10 -> 1010
        // [1,2,4,8,16]

        // [3,4,6,10,18..]
        // 10 ->

        int op = 65;
        int x = 1;

        while(op--){

            long long n = (long long)num1 - (long long)x*(long long)num2;
            cout << x << " " << n << endl;
            if(x > n)return -1;

            if(__builtin_popcountl(n) <= x)return x;    
            x++;
        }

        return -1;


    }
};
