class Solution {
public:

    int check(int x){
        int p = 0;
        while(x >= 4){
            p++;
            x/=4;
        }
        return p;
    }

    long long minOperations(vector<vector<int>>& q) {
        long long ans = 0;

        for(auto &i : q){
           int x = 0;

           long long a = i[0],b = i[1];
           long long n = (b - a + 1);
           long long p1 = check(a);
           long long p2 = check(b);

            int curr = a;
            // cout << a << " " << b << endl;
            // cout << p1 << " " << p2 << endl;
            long long temp = 0;

            for(int k = p1 +1;k<=p2 + 1;k++){
                // cout << "curr : " << curr << endl;
                if(pow(4,k) > b){
                    temp += (b - curr  + 1) * k;

                    
                }
                else{
                    temp += (pow(4,k) - curr) * k;
                    curr = pow(4,k);
                    
                }
                // cout << ans << endl;
            }
            ans += (temp + 1)/2;

        }
        return ans;
    }
};
/*
[3,4,5,6,7]



[2,3,4,5,6]
[0,0,4,5,6]
[0,0,1,1,6]
[0,0,0,1,1]
[0,0,0,0,0]
2

[14,15,16,17]
[3,3,16,17]
[0,0,16,17]
[0,0,4,4]
[0,0,1,1]
[0,0,0,0]


[12,15]
[12,13,14,15]
[3,3,14,15]
[0,3,3,15]
[0,0,3,3]
[0,0,0,0]

[17,18,19,20]
[4,4,19,20]
[4,4,4,4]
[1,1,4,4]
[0,0,4,4]
[0,0,1,1]
[0,0,0,0]

[17,18,19,20,21]
[4,4,19,20,21]
[1,4,4,20,21]
[0,4,1,20,21]
[0,1,1,5,21]
[0,0,1,1,21]
[0,0,0,1,5]
[0,0,0,0,1]
[0,0,0,0,0]

[62,63,64,65]
[15,15,64,65]
[15,15,16,16]
[3,3,16,16]
[0,0,16,16]
[0,0,4,4]
[0,0,1,1]
[0,0,0,0]

*/
