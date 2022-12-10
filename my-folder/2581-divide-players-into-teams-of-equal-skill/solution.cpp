class Solution {
public:
    long long dividePlayers(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        long long i = 0, j = n - 1;
        long long prev = 0,prod = 0;
        while(i <  j){
            int a = v[i];
            int b = v[j];
            if(prev == 0){
                prev = a + b;
                
                
                prod += (a* b);
            }
            else{
                if(a + b != prev)return -1;
                prod += (a* b);
            }
            i++;j--;
        }
        return prod;
    }
};
