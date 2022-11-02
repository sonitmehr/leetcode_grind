#define pb push_back
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define sortall(x) sort(all(x))
#define ll long long
#define m(x,y) map<x,y>
#define um(x,y) unordered_map<x,y>
#define vll vector<long long>
#define vvll vector<vector<ll>>
//#define f(i, n) for (ll i = 0; i < n; i++)
#define endl "\n"
#define nline cout << endl;
#define yyes cout << "YES"
#define nno cout << "NO"
#define debug(v) cout << "V [ ";\
        for(auto i : v) cout << i << " "; \
        cout << "]" << endl;
#define debugM(v) for(auto i : v) cout << "[ "<< i.first << " -> " << i.second << " ]" << endl;
class Solution {
public:
    int destroyTargets(vector<int>& v, int space) {
        int  n = v.size();
        m(ll,ll) m;
        ll maxi = 0;
        for(int i = 0;i<n;i++){
            m[v[i]%space]++;
            maxi = max(maxi,m[v[i]%space]);
        }
        ll ans = 1e9;
        for(int i = 0;i<n;i++){
            if(m[v[i]%space] == maxi){
                ans = min(ans,(ll)v[i]);
            }
        }
        return ans;
        // 1,1,3,5,7,8
        // 1,1,1,1,1,0
        
        // 1,3,5,2,4,6
        // 1,1,1,0,0,0
    }
};
