class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        unordered_map<int,int> mp;
        for(int i= 0;i<n - 1;i++){
            mp[i] = i + 1;
        }
        vector<int> ans;
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];

            if(mp.find(l) == mp.end() || mp[l] >= r){
                ans.push_back(mp.size());
                continue;
            }

            int j = mp[l];
            while(j < r){
                mp.erase(j);
                j ++;
            }
            mp[l] = r;
            ans.push_back(mp.size());
        }
        return ans;
    }
};
