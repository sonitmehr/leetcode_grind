class Solution {
public:
    int f(int t){
        int ans = 0,one = 0;
        int k = log2(t) + 1;
        while(one < k){
            if((1 << one) & (t)){
                ans++;
                //cout << (1 << one) << endl;
            }
            
            one++;
            
        }
        return ans;
    }
    int minOperations(int n) {
        int one = 0;
        
        // 2 + 4 + 16 + 32
        // 110110
        set<int> st;
        long long two = 1;
        for(int i  =0;i <32;i++){
            st.insert(two);
            two *= 2;
        }
        int ans1 = 1e9;
        int t = *st.lower_bound(n);
        
        for(int i = n+1;i<=1e5;i++){
            int diff = i - n;
            // int left = t - diff;
            ans1 = min(ans1,f(diff) + f(i));
            //cout << f(diff) << " " << f(i) << " " << ans1 << endl;
        }
        int ans2 = f(n);
        // cout << t << " ";
        //cout << n << " " << t << endl;
        //cout << ans1 << " " << ans2 << endl;
        return min(ans1,ans2);
        
    }
};
