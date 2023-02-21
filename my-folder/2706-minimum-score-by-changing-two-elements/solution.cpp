class Solution {
public:
    int minimizeSum(vector<int>& v) {
        int n = v.size();
        if(n == 1 || n == 2)return 0;
        sort(v.begin(),v.end());
        // 1 4 5 7 8
        // 1 1 5 7 8
        // 5 5 5 4 5
        // 58 42 8 75 28
        
        // 8  28 42 58 75
        // 8 28 42 42 42
        // 42 42 42 58 75
        
        // mini = 20
        // maxi = 67
        return min({v[n - 1] - v[2],v[n-3] - v[0],v[n -2] - v[1]});
    }
};
