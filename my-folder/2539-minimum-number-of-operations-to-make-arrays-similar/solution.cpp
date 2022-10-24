#define vll vector<long long>
#define pb push_back
#define all(x) x.begin(),x.end()
class Solution {
public:
    long long makeSimilar(vector<int>& v, vector<int>& target) {
        int n = v.size();
        
        vll even1,odd1,even2,odd2;
        
        for(int i = 0;i<n;i++){
            if(v[i]%2 == 0)even1.pb(v[i]);
            else odd1.pb(v[i]);
        }
        for(int i = 0;i<n;i++){
            if(target[i]%2 == 0)even2.pb(target[i]);
            else odd2.pb(target[i]);
        }
        long long ans = 0;
        sort(all(even1));sort(all(odd1));
        sort(all(even2));sort(all(odd2));
        for(int i = 0;i<even1.size();i++){
            ans += (abs(even1[i] - even2[i]))/2;
        }
        for(int i = 0;i<odd1.size();i++){
            ans += (abs(odd1[i] - odd2[i]))/2;
        }
        return ans/2;
        
        
    }
};
