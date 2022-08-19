class Solution {
public:
    bool isPossible(vector<int>& v) {
        int n = v.size();
        map<int,int> m;
        //set<int> set;
        int cnt = 0,maxi = 0;
        for(int i = 0;i<n;i++){
            m[v[i]]++;
            // set.insert(v[i]);
            // maxi = max(maxi,m[v[i]]);
        }
        for(auto i : v){
            int a =i;
            int prev = m[a];
            cnt = 0;
            if(m[a] == 0)continue;
            while(m[a]>0 && m[a] >= prev){
                prev = m[a];
                m[a]--;
                
                a++;
                cnt++;
            }          
            if(cnt <3)return false;
        }
        
        
        
        return true;        
        
    }
};
