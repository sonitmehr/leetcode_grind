class Solution {
public:
    int f(char c){
        return c - '0';
    }
    bool check(string &n, long long k) {
        long long rem = 0;
        for (auto i : n)
            rem = ((rem * 10) + i - '0') % k;
        return rem == 0;
    }
    vector<int> divisibilityArray(string s, int m) {
        vector<int> ans;
        int n = s.size();
        long long sum = 0;
        long long num = 0;
        string t;
        for(int i = 0;i<n;i++){
            int curr = f(s[i]);
            
            num = 10*num + curr;
            
            if(num%m == 0){
                ans.push_back(1);
                num = 0;
            }
            else{
                num = num % m;
                ans.push_back(0);
            } 
        }
        return ans;
    }
};
