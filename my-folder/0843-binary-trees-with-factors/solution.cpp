class Solution {
public:
    int  M = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        map <long long,long long> m;
        
        for(int i = 0;i<n;i++){
            m[v[i]]++;
        }
        long long sum = 0;
        for(int i =1;i<n;i++){
            long long cnt = 0;
            for(int j = 0;j<i;j++){
                if(v[i]%v[j] == 0){
                    if(m[v[i]/v[j]] > 0){
                        cnt += m[v[i]/v[j]]*m[v[j]];
                    }
                }
            }
            m[v[i]] += cnt;
        }
        
        for(auto i : m){
            sum += i.second;
        }return sum % M;
    }
};
