class Solution {
public:
    int f(int n) {
       int sum = 0;
       while(n > 0){
           sum += n%10;
           n/=10;
       }
       return sum;
    }
    int maximumSum(vector<int>& v) {
        int n = v.size();
        
        vector<pair<int,int>> ans(n);
        
        for(int i= 0;i<n;i++){
            ans[i].first = f(v[i]);
            ans[i].second = v[i];
        }
        sort(ans.begin(),ans.end());
        int curr = ans[n-1].first,ind = ans[n-1].second;
        int maxi = -1;
        for(int i = n-1;i>0;i--){
            
            if(ans[i].first == ans[i-1].first){
                //cout << "i " << ans[i].second <<" v[i] " << v[ans[i].second] << endl;
                //cout << "ans[i].first " << ans[i].first << " curr " << curr << endl;
                //cout << "v[ind] " << v[ind] << endl;
                maxi = max(ans[i].second + ans[i-1].second,maxi);
            }
            else{
                curr = ans[i-1].first;
            }
            
        }
        return maxi;
        
    }
    
};

//[18,43,36,13,7] = [4,7,7,9,9];
//[10,12,19,14]  = [1,1,3,5];
