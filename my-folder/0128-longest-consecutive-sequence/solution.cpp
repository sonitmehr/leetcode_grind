class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        set<int> set;
        int n = v.size();
        for(int i= 0;i<n;i++)set.insert(v[i]);
        if(set.size() == 0){
            return 0;
        }
        if(set.size() == 1)return 1;
        
        int prev = *(set.begin());
        auto i  = set.begin();
        i++;
        int cnt = 1;
        int ans = 1;
        for(;i!=set.end();i++){
            
            if(prev + 1 == *i){
                cnt ++;
                cout << *i << " ";
                ans = max(ans,cnt);
                prev = *i;
            }
            else{
                prev = *i;
                cnt = 1;
            }
            
        }
        return ans;
    }
};
