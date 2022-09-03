class Solution {
public:
    bool findSubarrays(vector<int>& v) {
        int n = v.size();
        map<int,int> m;
        for(int i= 0;i<n-1;i++){
            int sum = 0;
            sum += v[i];
            sum += v[i+1];
            m[sum]++;
        }
        for(auto i : m)if(i.second >=2)return true;
        return false;
    }
};
