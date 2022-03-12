class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long x  = num;
        
        // (x+1) = 11;
        vector<long long> v;
        if(x%3!=0)return v;
        x = x/3;
        v.push_back(x-1);
        v.push_back(x);
        v.push_back(x+1);
        return v;
    }
};
