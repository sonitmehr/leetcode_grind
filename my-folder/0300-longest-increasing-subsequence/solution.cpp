class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        vector<int> ans;
        int n = v.size();
        ans.push_back(v[0]);
        int maxi = 1;
        for(int i = 1;i<n;i++){
            auto it = lower_bound(ans.begin(),ans.end(),v[i]);
            //cout <<v[i] << " " << it - ans.begin() << endl;
            if(it == ans.end()){
                ans.push_back(v[i]);
            }
            else{
                //it--;
                int ind = it - ans.begin();
                ans[ind] = v[i];
            }
            maxi = max(maxi,(int)ans.size());
        }
        return maxi;

    }
};
