class Solution {
public:
    vector<int> goodIndices(vector<int>& v, int k) {
        // [2,1,1,1,3,4,1]
        int n =v.size();
        vector<int> ans;
        map<int,int> m;
        int prev = INT_MAX,cnt = 0;
        for(int i = 0;i<n;i++){
            if(cnt >= k){
                m[i]++;
            }
            if(v[i] <= prev){
                cnt++;
            }else cnt = 1;
            //cout << "cnt " << cnt << " m[i] " << m[i] << endl;
            prev = v[i];
        }
       
        cnt = 0;
        //cout << endl;
        prev = INT_MAX;
        for(int i = n-1;i>=0;i--){
            if(cnt >= k){
                m[i]++;
                
            }
            if(v[i] <= prev){
                cnt++;
            }
            else cnt = 1;
            //cout << "cnt " << cnt << " m[i] " << m[i] << endl;
            prev = v[i];
        }
        for(auto i : m){
            if(i.second >= 2)ans.push_back(i.first);
        }
        
        return ans;
        
    }
};
