class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& v, int k) {
        int n = v.size();
        vector<int> ans;
        map<int,int> m;
        int cnt = 0,prev = 1e9;
        if(k == 0){
            for(int i = 0;i<n;i++){
                ans.push_back(i);
            }
            return ans;
        }
        for(int i = 0;i<n;i++){
            if(cnt >= k && prev >= v[i])m[i]++;
            if(v[i] <= prev){
                cnt++;
            }
            else cnt = 1;
            
            prev = v[i];
        }
        cnt = 0;
        prev = INT_MAX;
        for(int i = n-1;i>=0;i--){
            if(cnt >= k && prev >= v[i])m[i]++;
            if(v[i] <= prev){
                cnt++;
            }
            else cnt = 1;
            
            prev = v[i];
        }
        
        for(auto i : m){
            if(i.second == 2)ans.push_back(i.first);
        }
        return ans;
    }
};
