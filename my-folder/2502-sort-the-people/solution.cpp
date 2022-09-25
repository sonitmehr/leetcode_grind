class Solution {
public:
    vector<string> sortPeople(vector<string>& v1, vector<int>& v2) {
        vector<pair<int,string>> v(v2.size());
        
        for(int i = 0;i<v2.size();i++){
            v[i] = {v2[i],v1[i]};
            
        }
        sort(v.rbegin(),v.rend());
        vector<string> ans;
        for(auto i : v){
            ans.push_back(i.second);
        }
        return ans;
    }
};
