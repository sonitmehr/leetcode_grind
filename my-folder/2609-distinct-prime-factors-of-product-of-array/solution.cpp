class Solution {
public:
    set<long long> st;
    void primeFactors(long long n)
    {   
        
        long long c=2;
        while(n>1)
        {
            if(n%c==0){
            st.insert(c);
            n/=c;
            }
            else c++;
        }
        //return st.size();
    }
    int distinctPrimeFactors(vector<int>& nums) {
        long long prod = 1;
        int n = nums.size();
        long long sum = 0;
        for(int i = 0;i<n;i++){
            primeFactors(nums[i]);
        }
        return st.size();
        
    }
};
