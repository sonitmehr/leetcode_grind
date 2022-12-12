class Solution {
public:
    int longestSquareStreak(vector<int>& v) {
        int n = v.size();
        unordered_map<long long,long long> m;
        for(int i =0;i<n;i++){
            m[v[i]]++;
        }
        long long maxi = -1,cnt = 0;
        for(int i = 0;i<n;i++){
            long long curr = v[i];
            cnt = 1;
            long long sq = pow(curr,2);
            
            while(m[sq] > 0){
                cnt++;
                //cout << sq << " " << cnt << endl;
                sq *= sq;
                maxi = max(maxi,cnt);
            }
            
        }
        return maxi;
    }
};
